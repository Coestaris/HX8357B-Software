from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw 
from PIL import ImageColor 

import logging

import config_keys

dummy = Image.new('1', (200, 200))
dummyDraw = ImageDraw.Draw(dummy)

def get_font(config):
    if(config.font.type == config_keys.KEY_FONT_TYPE_DEFAULT):
        return ImageFont.load_default()
    elif(config.font.type == config_keys.KEY_FONT_TYPE_SYSTEM):
        return ImageFont.load(config.font.id)
    else:
        return ImageFont.load_path(config.font.id)

def get_position(size1, size2, config):
    if(config.font.positioning == config_keys.KEY_FONT_POSITIONING_ZERO):
        return (0, 0)
    elif(config.font.positioning == config_keys.KEY_FONT_POSITIONING_CENTERED):
        return (
            int((size1[0] - size2[0]) / 2),
            int((size1[1] - size2[1]) / 2),
        )
    else: 
        return (
            int((size1[0] - size2[0]) / 2),
            size1[1] - size2[1],
        )

def generate_ti(images, config):
    logger = logging.getLogger(__name__)
    logger.info("Generating Total Image (ti)...")

    imSize = images[0].size
    size = config.output.ti.imagesPerRow * (imSize[0] + 1), ((len(images) // config.output.ti.imagesPerRow) + 1) * (imSize[1] + 1)
    ti = Image.new('RGB', size, ImageColor.getrgb("#%s" % config.output.ti.sepColor))

    xC, yC = 0, 0
    for index, val in enumerate(config.symbols):
        ti.paste(images[index], (xC * (imSize[0] + 1), yC * (imSize[1] + 1)))
        
        if((index) % config.output.ti.imagesPerRow == 0 and index != 0): xC, yC = 0, yC + 1
        else: xC += 1
    try:
        ti.save(config.output.filesDir + '/' + config.output.ti.name)
    except Exception as ex:
        logger.error("Unable to save ti\nError: %s" % ex)

    logger.info("Generating done")
    return ti

def generate_image_list(config):
    logger = logging.getLogger(__name__)
    logger.info("Generating image list")
    
    font = None
    size = (config.symbolSize.width, config.symbolSize.height)
    images = []
    
    try:
        font = get_font(config)
    except Exception as ex:
        logger.error("Unable to load font.\nError: %s", ex)
        return
    logger.info("Font loaded")

    if(config.font.sizeMode == config_keys.KEY_FONT_SIZEMODE_AUTOSIZE):
        maxW, maxH = 0, 0
        for i in config.symbols:
            currentSize = dummyDraw.textsize(chr(i), font=font)
            if(currentSize[0] > maxW): maxW = currentSize[0]
            if(currentSize[1] > maxH): maxH = currentSize[1]
        size = (maxW, maxH)

    for i in config.symbols:
        im = None
        text = chr(i)

        if(config.font.sizeMode == config_keys.KEY_FONT_SIZEMODE_STRETCH):
            smallSize = dummyDraw.textsize(text, font=font)

            smallIm = Image.new('1', smallSize)
            smallDraw = ImageDraw.Draw(smallIm)
            smallDraw.text((0, 0), text, 1, font=font)

            toResizeByX = size[0] / smallSize[0]                
            toResizeByY = size[1] / smallSize[1]
            maxResizeFactor = min(toResizeByX, toResizeByY)                

            newSize = round(smallSize[0] * maxResizeFactor), round(smallSize[1] * maxResizeFactor)

            smallIm = smallIm.resize( 
                newSize,
                Image.BICUBIC,
            )

            im = Image.new('1', size)
            im.paste(
                smallIm,
                get_position(size, newSize, config)
            )

        else:
            im = Image.new('1', size)
            draw = ImageDraw.Draw(im)
            draw.text(
                get_position(size, dummyDraw.textsize(text, font=font), config), 
                text, 
                1, 
                font=font
            )

        try:
            im.save(config.output.filesDir + '/' + config.output.filesNameFormat % i)
        except Exception as ex:
            logger.error("Unable to save output file\nError: %s" % ex)

        images.append(im)
    
    logger.info("Generating done")


    if(config.output.ti.save):
        generate_ti(images, config)

    return images