from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw 
from PIL import ImageColor 

import logging

import helpers
import config_keys

import fontcache

dummy = Image.new('1', (200, 200))
dummyDraw = ImageDraw.Draw(dummy)


class font:

    def __init__(self, images, cache):
        self.images = images
        self.cache = cache
        pass

    def fonttest(self, config):
        xspacing = 5
        yspacing = 5

        logger = logging.getLogger("font:test")
        logger.info("Creating test image...")

        mx, x, y = 0, 0, 1
        for char in config.action.fontTestString:
            if(char == '\n'): 
                y += 1
                if(x > mx): mx = x
                x = 0
            
            else: x += 1
        if(x > mx): mx = x
        
        imsize = self.images[0].size
        size = mx * (imsize[0] + xspacing), y * (imsize[1] + yspacing)

        im = Image.new('1', size)
        x, y = 0, 0
        for ind, char in enumerate(config.action.fontTestString):
            imToCopy = None
            if(char == '\n'): 
                y += imsize[1] + yspacing
                x = 0

            else:
                if(ord(char) in self.cache.charDict): imToCopy = self.images[self.cache.charDict[ord(char)]]
                else: imToCopy = self.images[self.cache.charDict[self.cache.nullChar]]

                im.paste(imToCopy, (x, y))
                x += imsize[0] + xspacing
            
        try:
            im.save(config.nfp.output.makePath(config.action.output_test))
        except Exception as ex:
            logger.error("Unable to save file \"%s\"\nError: %s" % (config.nfp.output.makePath(config.action.output_test), ex))
            return

            

    def save_images(self, config):
        logger = logging.getLogger("font:save:images")
        logger.info("Generating images...")

        for ind, val in enumerate(self.images):
            name = config.nfp.output.makePath(config.nfp.output.files.fnf % ind)
            try:
                val.save(name)
            except Exception as ex:
                logger.error("Unable to save file \"%s\"\nError: %s" % (name, ex))
                return

        logger.info("Saving done")


    def save_ti(self, config):
        logger = logging.getLogger("font:save:ti")
        logger.info("Generating Total Image (ti)")

        imSize = self.images[0].size
        size = config.nfp.output.ti.imagesPerRow * (imSize[0] + 1), ((len(self.images) // config.nfp.output.ti.imagesPerRow) + 1) * (imSize[1] + 1)
        ti = Image.new('RGB', size, ImageColor.getrgb("#%s" % config.nfp.output.ti.sepColor))

        xC, yC = 0, 0
        for index, val in enumerate(config.nfp.symbols):
            ti.paste(self.images[index], (xC * (imSize[0] + 1), yC * (imSize[1] + 1)))
            
            if((index) % config.nfp.output.ti.imagesPerRow == 0 and index != 0): xC, yC = 0, yC + 1
            else: xC += 1
        try:
            ti.save(config.nfp.output.makePath(config.nfp.output.ti.name))
        except Exception as ex:
            logger.error("Unable to save ti\nError: %s" % ex)

        logger.info("Image saved")

        logger.info("Writing cache")

        try:
            self.cache.save(config.nfp.output.makePath(config.nfp.output.cacheFn))
        except Exception as ex:
            logger.error("Unable to save cache\nError: %s" % ex)
            
        return ti

def load_ti(config):
    pass

def new(config):
    logger = logging.getLogger("font:new")
    logger.info("Creating new font")
    
    builtinFont = None
    size = (config.nfp.symbolSize.width, config.nfp.symbolSize.height)
    images = []
    
    try:
        builtinFont = helpers.get_font(config)
    except Exception as ex:
        logger.error("Unable to builtin load font.\nError: %s", ex)
        return

    logger.info("Builtin font loaded")

    if(config.nfp.sizeMode == config_keys.KEY_NFP_SIZEMODE_AUTOSIZE):
        maxW, maxH = 0, 0
        for i in config.nfp.symbols:
            currentSize = dummyDraw.textsize(chr(i), font=builtinFont)
            if(currentSize[0] > maxW): maxW = currentSize[0]
            if(currentSize[1] > maxH): maxH = currentSize[1]
        size = (maxW, maxH)

    charDict = {}

    for index, charCode in enumerate(config.nfp.symbols):
        im = None
        text = chr(charCode)

        if(config.nfp.sizeMode == config_keys.KEY_NFP_SIZEMODE_STRETCH):
            smallSize = dummyDraw.textsize(text, font=builtinFont)

            smallIm = Image.new('1', smallSize)
            smallDraw = ImageDraw.Draw(smallIm)
            smallDraw.text((0, 0), text, 1, font=builtinFont)

            toResizeByY, toResizeByX = 0, 0
            if(smallSize[0] == 0 or smallSize[1] == 0):
                 toResizeByY, toResizeByX = 1, 1
            
            else:
                toResizeByX = size[0] / smallSize[0]                
                toResizeByY = size[1] / smallSize[1]

            maxResizeFactor = min(toResizeByX, toResizeByY)                

            newSize = round(smallSize[0] * maxResizeFactor), round(smallSize[1] * maxResizeFactor)
            smallIm = smallIm.resize(newSize, Image.BICUBIC)

            im = Image.new('1', size)
            im.paste(smallIm, helpers.get_position(size, newSize, config))

        else:
            im = Image.new('1', size)
            draw = ImageDraw.Draw(im)
            draw.text(
                helpers.get_position(size, dummyDraw.textsize(text, font=builtinFont), config), 
                text, 
                1, 
                font=builtinFont
            )

        images.append(im)
        charDict.update({ charCode : index })

    cache = fontcache.fontcache(
        nullChar=config.nfp.nullChar,
        charDict = charDict,
        charSize = size
    )

    logger.info("Generating done")
    return font(images, cache)
