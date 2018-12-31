from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw 

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

            smallIm.save("output/_%s.png" % i)

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
            im.save("output/%s.png" % i)
        except Exception as ex:
            logger.error("Unable to save output file\nError: %s" % ex)

        images.append(im)
    pass