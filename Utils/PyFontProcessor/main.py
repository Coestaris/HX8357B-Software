from PIL import Image, ImageFont
import sys
import json
import logging

import config
import config_keys
import font

logging.basicConfig(format='%(asctime)s - (%(name)s) [%(levelname)s]: %(message)s', level=logging.INFO)

def main():
    logger = logging.getLogger("main")
    configName = "сfg.json"
    
    if(len(sys.argv) != 1):
        configName = sys.argv[1]
    
    logger.info("Config name is %s. Loading...", configName)
    conf = config.config.load(configName)
    
    if(conf == None): return

    logger.info("Configuration file loaded")

    logger.info("Loading/creating font")
    currentFont = font.font(None, None)

    # Loading font
    if(conf.action.fontSource == config_keys.KEY_ACTION_FONTSOURCE_NEW):
        currentFont = font.new(conf)
    elif(conf.action.fontSource == config_keys.KEY_ACTION_FONTSOURCE_TI):
        currentFont = font.load_ti(conf)
    # ===

    if(currentFont == None or currentFont.images == None):
        logger.error("Unable to load/create font. Cant proceed further action")
        return

    # Doing action
    if(conf.action.type == config_keys.KEY_ACTION_TYPE_FONTTEST):
        currentFont.fonttest(conf)

    else:
        if(conf.action.saveAs == config_keys.KEY_ACTION_SAVEAS_TI):
            currentFont.save_ti(conf)
        elif(conf.action.saveAs == config_keys.KEY_ACTION_SAVEAS_IMAGES):
            currentFont.save_images(conf)

    # ===
if __name__ == "__main__":
    main()