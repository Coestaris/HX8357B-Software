from PIL import Image, ImageFont
import sys
import json
import logging

import processor
import config

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', level=logging.INFO)

def main():
    logger = logging.getLogger(__name__)
    configName = "сfg.json"
    
    if(len(sys.argv) != 1):
        configName = sys.argv[1]
    
    logger.log(logging.INFO, "Config name is %s. Loading...", configName)
    conf = config.config.load(configName)
    
    if(conf == None): return

    logger.log(logging.INFO, "Conf loaded. %s", conf.toJSON())
    
    processor.generate_image_list(conf)

if __name__ == "__main__":
    main()