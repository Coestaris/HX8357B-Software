from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw 
from PIL import ImageColor 

import logging

import helpers
import config_keys

dummy = Image.new('1', (200, 200))
dummyDraw = ImageDraw.Draw(dummy)


class font:

    def __init__(self, images):
        self.images = images
        pass

    def save_to_images(self, config):
        pass

    def save_ti(self, config):
        logger = logging.getLogger("font:save:ti")
        logger.info("Generating Total Image (ti)...")

        imSize = self.images[0].size
        size = config.nfp.output.ti.imagesPerRow * (imSize[0] + 1), ((len(self.images) // config.nfp.output.ti.imagesPerRow) + 1) * (imSize[1] + 1)
        ti = Image.new('RGB', size, ImageColor.getrgb("#%s" % config.nfp.output.ti.sepColor))

        xC, yC = 0, 0
        for index, val in enumerate(config.nfp.symbols):
            ti.paste(self.images[index], (xC * (imSize[0] + 1), yC * (imSize[1] + 1)))
            
            if((index) % config.nfp.output.ti.imagesPerRow == 0 and index != 0): xC, yC = 0, yC + 1
            else: xC += 1
        try:
            ti.save(config.nfp.output.outdir + '/' + config.nfp.output.ti.name)
        except Exception as ex:
            logger.error("Unable to save ti\nError: %s" % ex)

        logger.info("Generating done")
        return ti

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

    for i in config.nfp.symbols:
        im = None
        text = chr(i)

        if(config.nfp.sizeMode == config_keys.KEY_NFP_SIZEMODE_STRETCH):
            smallSize = dummyDraw.textsize(text, font=builtinFont)

            smallIm = Image.new('1', smallSize)
            smallDraw = ImageDraw.Draw(smallIm)
            smallDraw.text((0, 0), text, 1, font=builtinFont)

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

    logger.info("Generating done")
    return font(images)
