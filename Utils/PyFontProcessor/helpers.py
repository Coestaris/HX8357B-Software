from PIL import ImageFont

import config_keys

def get_font(config):
    if(config.nfp.type == config_keys.KEY_NFP_TYPE_DEFAULT):
        return ImageFont.load_default()
    elif(config.nfp.type == config_keys.KEY_NFP_TYPE_SYSTEM):
        return ImageFont.load(config.font.id)
    else:
        return ImageFont.load_path(config.font.id)

def get_position(size1, size2, config):
    if(config.nfp.positioning == config_keys.KEY_NFP_POSITIONING_ZERO):
        return (0, 0)

    elif(config.nfp.positioning == config_keys.KEY_NFP_POSITIONING_CENTERED):
        return (int((size1[0] - size2[0]) / 2), int((size1[1] - size2[1]) / 2))

    else: 
        return (int((size1[0] - size2[0]) / 2), size1[1] - size2[1])