import json
import re
import logging

import config_keys

class ParseConfigError(Exception):
    def __init__(self, message):
        self.message = message

    def __str__(self):
        return self.message

class size:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    @staticmethod
    def parse_from_dict(dict):
        return size(
                width=dict[ config_keys.KEY_SYMBOLSIZE_W ],
                height=dict[ config_keys.KEY_SYMBOLSIZE_H ]
            )

    def toJSON(self):
        return {
           config_keys.KEY_SYMBOLSIZE_W : self.height,
           config_keys.KEY_SYMBOLSIZE_H : self.height
        }

class tiInfo:
    def __init__(self, save, name, imagesPerRow, sepColor):
        self.save = save
        self.name = name
        self.imagesPerRow = imagesPerRow
        self.sepColor = sepColor

    def toJSON(self):
        return {
            config_keys.KEY_OUTPUT_TI_NAME : self.name,
            config_keys.KEY_OUTPUT_TI_SAVE : self.save,
            config_keys.KEY_OUTPUT_TI_IMAGESPERROW : self.imagesPerRow,
            config_keys.KEY_OUTPUT_TI_SEPCOLOR : self.sepColor,
        }

class outputInfo:
    def __init__(self, filesDir, filesNameFormat, ti):
        self.filesDir = filesDir
        self.filesNameFormat = filesNameFormat
        self.ti = ti

    def toJSON(self):
        return {
           config_keys.KEY_OUTPUT_FILESDIR : self.filesDir,
           config_keys.KEY_OUTPUT_FILESNF : self.filesNameFormat,
           config_keys.KEY_OUTPUT_TI : self.ti.toJSON()
        }

class fontInfo:
    def __init__(self, encoding, type, id, size, sizeMode, positioning):
        self.encoding = encoding
        self.type = type
        self.id = id
        self.size = size
        self.sizeMode = sizeMode
        self.positioning = positioning

    def toJSON(self):
        return {
            config_keys.KEY_FONT_ENCODING : self.encoding,
            config_keys.KEY_FONT_TYPE : self.type,
            config_keys.KEY_FONT_NAME : self.id,
            config_keys.KEY_FONT_SIZE : self.size,
            config_keys.KEY_FONT_SIZEMODE : self.sizeMode,
            config_keys.KEY_FONT_POSITIONING : self.positioning
        }

def removeComments(string):
    string = re.sub(re.compile("/\*.*?\*/",re.DOTALL ) ,"" ,string) # remove all occurance streamed comments (/*COMMENT */) from string
    string = re.sub(re.compile("//.*?\n" ) ,"" ,string) # remove all occurance singleline comments (//COMMENT\n ) from string
    return string

class config:
    
    @staticmethod
    def get_dict_value(dict, key):
        key = key.lower()
        if(key in dict): return dict[key]
        else: raise ParseConfigError("Unable to find key \"%s\" in dictionary" % key)

    @staticmethod
    def get_outputinfo(dict):
        tiDict = config.get_dict_value(dict, config_keys.KEY_OUTPUT_TI)
        return outputInfo(
            filesDir=config.get_dict_value(dict, config_keys.KEY_OUTPUT_FILESDIR),
            filesNameFormat=config.get_dict_value(dict, config_keys.KEY_OUTPUT_FILESNF),
            ti=tiInfo(
                save=config.get_dict_value(tiDict, config_keys.KEY_OUTPUT_TI_SAVE),
                name=config.get_dict_value(tiDict, config_keys.KEY_OUTPUT_TI_NAME),
                imagesPerRow=config.get_dict_value(tiDict, config_keys.KEY_OUTPUT_TI_IMAGESPERROW),
                sepColor=config.get_dict_value(tiDict, config_keys.KEY_OUTPUT_TI_SEPCOLOR)
            )
        )

    @staticmethod
    def get_fontinfo(dict):
        if(config_keys.KEY_FONT_TYPE not in dict): 
            raise ParseConfigError("\"%s\" dictionary have to contain \"%s\" section" % (config_keys.KEY_FONT, config_keys.KEY_FONT_TYPE))
        
        if(dict[ config_keys.KEY_FONT_TYPE ] not in config_keys.allowed_fonttypes): 
            raise ParseConfigError("\"%s\" is not allowed value" % (dict[config_keys.KEY_FONT_TYPE ]))

        if(config_keys.KEY_FONT_SIZEMODE not in dict):
            raise ParseConfigError("\"%s\" dictionary have to contain \"%s\" section"  % (config_keys.KEY_FONT, config_keys.KEY_FONT_SIZEMODE))
        
        elif(dict[ config_keys.KEY_FONT_SIZEMODE ] not in config_keys.allowed_fontmodes):
            raise ParseConfigError("\"%s\" is not allowed value"  % (dict[config_keys.KEY_FONT_SIZEMODE ]))

        id = None
        type = config_keys.KEY_FONT_TYPE_DEFAULT

        if(dict[ config_keys.KEY_FONT_TYPE ] == config_keys.KEY_FONT_TYPE_SYSTEM):
            id = config.get_dict_value(dict, config_keys.KEY_FONT_NAME)
            type = config_keys.KEY_FONT_TYPE_SYSTEM

        if(dict[ config_keys.KEY_FONT_TYPE ] == config_keys.KEY_FONT_TYPE_BYPATH):
            id = config.get_dict_value(dict, config_keys.KEY_FONT_PATH)
            type = config_keys.KEY_FONT_TYPE_BYPATH

        if(config_keys.KEY_FONT_POSITIONING not in dict):
            raise ParseConfigError("\"%s\" dictionary have to contain \"%s\" section"  % (config_keys.KEY_FONT, config_keys.KEY_FONT_POSITIONING))
        
        elif(dict[ config_keys.KEY_FONT_POSITIONING ] not in config_keys.allowed_fontpositioning):
            raise ParseConfigError("\"%s\" is not allowed value"  % (dict[config_keys.KEY_FONT_POSITIONING ]))

        return fontInfo(
                encoding=config.get_dict_value(dict, config_keys.KEY_FONT_ENCODING),
                type=type,
                id=id,
                size=config.get_dict_value(dict, config_keys.KEY_FONT_SIZE),
                sizeMode=dict[config_keys.KEY_FONT_SIZEMODE],
                positioning=dict[config_keys.KEY_FONT_POSITIONING])

    @staticmethod
    def get_symbol_list(dict):
        if(config_keys.KEY_SYMBOLS_TYPE not in dict): 
            raise ParseConfigError("\"%s\" dictionary have to contain \"%s\" section" % (config_keys.KEY_SYMBOLS, config_keys.KEY_SYMBOLS_TYPE))
        
        if(dict[ config_keys.KEY_SYMBOLS_TYPE ] not in config_keys.allowed_symbolstypes): 
            raise ParseConfigError("\"%s\" is not allowed value" % dict[ config_keys.KEY_SYMBOLS_TYPE ])

        if(dict[ config_keys.KEY_SYMBOLS_TYPE ] == config_keys.KEY_SYMBOLS_TYPE_RANGE):

            start = config.get_dict_value(dict, config_keys.KEY_SYMBOLS_TYPE_RANGE_START)
            end = config.get_dict_value(dict, config_keys.KEY_SYMBOLS_TYPE_RANGE_END)
            return range(start, end)
        
        if(dict[ config_keys.KEY_SYMBOLS_TYPE ] == config_keys.KEY_SYMBOLS_TYPE_LIST):
            return config.get_dict_value(dict, config_keys.KEY_SYMBOLS_TYPE_LIST_LIST)

    def __init__(self, font = None,  symbols = {}, symbolSize = size(20, 10), output = None):
        self.font = font
        self.symbols = config.get_symbol_list(symbols)
        self.symbolSize = symbolSize
        self.output = output

    @staticmethod
    def load(path):
        logger = logging.getLogger(__name__)

        try:
            with open(path, encoding="utf8") as f:

                input_str = removeComments(f.read().lower())
              
                data = json.loads(input_str)
                return config(
                        font=config.get_fontinfo(config.get_dict_value(data, config_keys.KEY_FONT)),   
                        symbols=config.get_dict_value(data, config_keys.KEY_SYMBOLS),   
                        symbolSize=size.parse_from_dict(config.get_dict_value(data, config_keys.KEY_SYMBOLSIZE)),
                        output=config.get_outputinfo(config.get_dict_value(data, config_keys.KEY_OUTPUT))
                    )
        
        except IOError as ex:
            logger.log(logging.ERROR, "Unable to open or read file %s.\nError: %s", path, ex)
            return None

        except (json.JSONDecodeError, ParseConfigError) as ex:
            logger.log(logging.ERROR, "Unable to parse JSON.\nError: %s", ex)
            return None

        except Exception as ex:
            logger.log(logging.ERROR, "Unhandled error happened while parsing JSON.\nError: %s", ex)
            return None

    def toJSON(self):
        return {
            config_keys.KEY_FONT : self.font.toJSON(),
            config_keys.KEY_SYMBOLS : self.symbols,
            config_keys.KEY_SYMBOLSIZE : self.symbolSize.toJSON(),
            config_keys.KEY_OUTPUT : self.output.toJSON()
        }