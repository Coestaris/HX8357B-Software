from PIL import ImageFont

import re

import config_keys

def get_font(config):
    if(config.nfp.type == config_keys.KEY_NFP_TYPE_DEFAULT):
        return ImageFont.load_default()
    elif(config.nfp.type == config_keys.KEY_NFP_TYPE_BITMAP):
        return ImageFont.load(config.nfp.id)
    else:
        return ImageFont.truetype(config.nfp.id, size=config.nfp.size, encoding=config.nfp.encoding)
        #KEY_NFP_TYPE_TTF

def get_position(size1, size2, config):
    if(config.nfp.positioning == config_keys.KEY_NFP_POSITIONING_ZERO):
        return (0, 0)

    elif(config.nfp.positioning == config_keys.KEY_NFP_POSITIONING_CENTERED):
        return (int((size1[0] - size2[0]) / 2), int((size1[1] - size2[1]) / 2))

    else: 
        return (int((size1[0] - size2[0]) / 2), size1[1] - size2[1])

def removeComments(string):
    string = re.sub(re.compile(r"/\*.*?\*/", re.DOTALL), "", string) # remove all occurance streamed comments (/*COMMENT */) from string
    string = re.sub(re.compile(r"//.*?\n"), "", string) # remove all occurance singleline comments (//COMMENT\n ) from string
    return string