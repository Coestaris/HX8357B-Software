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

    def toJSON(self):
        return {
           config_keys.KEY_NFP_SYMBOLSIZE_W : self.height,
           config_keys.KEY_NFP_SYMBOLSIZE_H : self.height
        }

class tiInfo:
    def __init__(self, save, name, imagesPerRow, sepColor):
        self.save = save
        self.name = name
        self.imagesPerRow = imagesPerRow
        self.sepColor = sepColor

    def toJSON(self):
        return {
            config_keys.KEY_NFP_OUTPUT_TI_NAME : self.name,
            config_keys.KEY_NFP_OUTPUT_TI_SAVE : self.save,
            config_keys.KEY_NFP_OUTPUT_TI_IMAGESPERROW : self.imagesPerRow,
            config_keys.KEY_NFP_OUTPUT_TI_SEPCOLOR : self.sepColor,
        }

class filesInfo:
    def __init__(self, save, fnf):
        self.save = save
        self.fnf = fnf
    
    def toJSON(self): 
        return {
            config_keys.KEY_NFP_OUTPUT_FILES_SAVE : self.save,
            config_keys.KEY_NFP_OUTPUT_FILES_FNF : self.fnf,
        }

class outputInfo:
    def __init__(self, outdir, files, ti):
        self.outdir = outdir
        self.files = files
        self.ti = ti

    def toJSON(self):
        return {
            config_keys.KEY_NFP_OUTPUT_OUTDIR : self.outdir,
            config_keys.KEY_NFP_OUTPUT_FILES : self.files.toJSON(),
            config_keys.KEY_NFP_OUTPUT_TI : self.ti.toJSON()
        }

class fontInfo:
    def __init__(self, encoding, type, id, size, sizeMode, positioning, output, symbols, symbolSize):
        self.encoding = encoding
        self.type = type
        self.id = id
        self.size = size
        self.sizeMode = sizeMode
        self.positioning = positioning
        self.output = output
        self.symbols = symbols
        self.symbolSize = symbolSize

    def toJSON(self):
        return {
            config_keys.KEY_NFP_ENCODING : self.encoding,
            config_keys.KEY_NFP_TYPE : self.type,
            config_keys.KEY_NFP_NAME : self.id,
            config_keys.KEY_NFP_SIZE : self.size,
            config_keys.KEY_NFP_SIZEMODE : self.sizeMode,
            config_keys.KEY_NFP_POSITIONING : self.positioning,
            config_keys.KEY_NFP_OUTPUT : self.output.toJSON(),
            config_keys.KEY_NFP_SS : self.symbols,
            config_keys.KEY_NFP_SYMBOLSIZE : self.symbolSize
        }

class actionInfo:
    def __init__(self, type, fontSource, fontPath, saveAs, saveFontEncoding, fontTestString,
            output_header, output_binary, output_test):
        self.type = type
        self.fontSource = fontSource
        self.fontPath = fontPath
        self.saveAs = saveAs
        self.saveFontEncoding = saveFontEncoding
        self.fontTestString = fontTestString
        self.output_header = output_header
        self.output_binary = output_binary
        self.output_test = output_test

    def toJSON(self):
        return {
            config_keys.KEY_ACTION_TYPE : self.type,
            config_keys.KEY_ACTION_FONTSOURCE : self.fontSource,
            config_keys.KEY_ACTION_FONTPATH : self.fontPath,
            config_keys.KEY_ACTION_SAVEAS : self.saveAs,
            config_keys.KEY_ACTION_SAVEFONTENCODING : self.saveFontEncoding,
            config_keys.KEY_ACTION_FONTTESTSTRING : self.fontTestString,
            config_keys.KEY_ACTION_OUT_HEADER : self.output_header,
            config_keys.KEY_ACTION_OUT_BINARY : self.output_binary,
            config_keys.KEY_ACTION_OUT_TEST: self.output_test,
            
        }

def removeComments(string):
    string = re.sub(re.compile(r"/\*.*?\*/", re.DOTALL), "", string) # remove all occurance streamed comments (/*COMMENT */) from string
    string = re.sub(re.compile(r"//.*?\n"), "", string) # remove all occurance singleline comments (//COMMENT\n ) from string
    return string

class config:
    
    @staticmethod
    def get_dict_value(dict, key):
        key = key.lower()
        if(key in dict): return dict[key]
        else: raise ParseConfigError("Unable to find key \"%s\" in dictionary" % key)

    @staticmethod
    def get_actioninfo(dict):
        if(config.get_dict_value(dict, config_keys.KEY_ACTION_TYPE) not in config_keys.allowed_actiontypes):
            raise ParseConfigError("\"%s\" is not allowed value for \"%s\"" % (dict[config_keys.KEY_ACTION_TYPE ], config_keys.KEY_ACTION_TYPE))

        if(config.get_dict_value(dict, config_keys.KEY_ACTION_FONTSOURCE) not in config_keys.allowed_fontsources):
            raise ParseConfigError("\"%s\" is not allowed value for \"%s\"" % (dict[config_keys.KEY_ACTION_FONTSOURCE ], config_keys.KEY_ACTION_FONTSOURCE))
    
        if(config.get_dict_value(dict, config_keys.KEY_ACTION_SAVEAS) not in config_keys.allowed_saveAs):
            raise ParseConfigError("\"%s\" is not allowed value for \"%s\"" % (dict[config_keys.KEY_ACTION_SAVEAS ], config_keys.KEY_ACTION_SAVEAS))
        
        if(config.get_dict_value(dict, config_keys.KEY_ACTION_SAVEFONTENCODING) not in config_keys.allowed_saveFontEncoding):
            raise ParseConfigError("\"%s\" is not allowed value for \"%s\"" % (dict[config_keys.KEY_ACTION_SAVEFONTENCODING], config_keys.KEY_ACTION_SAVEFONTENCODING))
    
        return actionInfo(
            type=config.get_dict_value(dict, config_keys.KEY_ACTION_TYPE),
            fontSource=config.get_dict_value(dict, config_keys.KEY_ACTION_FONTSOURCE),
            fontPath=config.get_dict_value(dict, config_keys.KEY_ACTION_FONTPATH),
            saveAs=config.get_dict_value(dict, config_keys.KEY_ACTION_SAVEAS),
            saveFontEncoding=config.get_dict_value(dict, config_keys.KEY_ACTION_SAVEFONTENCODING),
            fontTestString=config.get_dict_value(dict, config_keys.KEY_ACTION_FONTTESTSTRING),
            output_header=config.get_dict_value(dict, config_keys.KEY_ACTION_OUT_HEADER),
            output_binary=config.get_dict_value(dict, config_keys.KEY_ACTION_OUT_BINARY),
            output_test=config.get_dict_value(dict, config_keys.KEY_ACTION_OUT_TEST),
        )

    @staticmethod
    def get_outputinfo(dict):
        tiDict = config.get_dict_value(dict, config_keys.KEY_NFP_OUTPUT_TI)
        fiDict = config.get_dict_value(dict, config_keys.KEY_NFP_OUTPUT_FILES)

        return outputInfo(
            outdir=config.get_dict_value(dict, config_keys.KEY_NFP_OUTPUT_OUTDIR),
            files= filesInfo(
                save=config.get_dict_value(fiDict, config_keys.KEY_NFP_OUTPUT_FILES_SAVE),
                fnf=config.get_dict_value(fiDict, config_keys.KEY_NFP_OUTPUT_FILES_FNF)
            ),            
            ti=tiInfo(
                save=config.get_dict_value(tiDict, config_keys.KEY_NFP_OUTPUT_TI_SAVE),
                name=config.get_dict_value(tiDict, config_keys.KEY_NFP_OUTPUT_TI_NAME),
                imagesPerRow=config.get_dict_value(tiDict, config_keys.KEY_NFP_OUTPUT_TI_IMAGESPERROW),
                sepColor=config.get_dict_value(tiDict, config_keys.KEY_NFP_OUTPUT_TI_SEPCOLOR)
            )
        )

    @staticmethod
    def get_fontinfo(dict):

        if(config.get_dict_value(dict, config_keys.KEY_NFP_TYPE) not in config_keys.allowed_fonttypes): 
            raise ParseConfigError("\"%s\" is not allowed value for \"%s\"" % (dict[config_keys.KEY_NFP_TYPE ], config_keys.KEY_NFP_TYPE))

        if(config.get_dict_value(dict, config_keys.KEY_NFP_SIZEMODE) not in config_keys.allowed_fontmodes):
            raise ParseConfigError("\"%s\" is not allowed value  for \"%s\""  % (dict[config_keys.KEY_NFP_SIZEMODE ], config_keys.KEY_NFP_SIZEMODE))

        id = None
        type = config_keys.KEY_NFP_TYPE_DEFAULT

        if(config.get_dict_value(dict, config_keys.KEY_NFP_TYPE) == config_keys.KEY_NFP_TYPE_SYSTEM):
            id = config.get_dict_value(dict, config_keys.KEY_NFP_NAME)
            type = config_keys.KEY_NFP_TYPE_SYSTEM

        if(config.get_dict_value(dict, config_keys.KEY_NFP_TYPE) == config_keys.KEY_NFP_TYPE_BYPATH):
            id = config.get_dict_value(dict, config_keys.KEY_NFP_PATH)
            type = config_keys.KEY_NFP_TYPE_BYPATH

        if(config.get_dict_value(dict, config_keys.KEY_NFP_POSITIONING) not in config_keys.allowed_fontpositioning):
            raise ParseConfigError("\"%s\" is not allowed value for \"%s\""  % (dict[config_keys.KEY_NFP_POSITIONING ], config_keys.KEY_NFP_POSITIONING))

        ssdict = config.get_dict_value(dict, config_keys.KEY_NFP_SS)
        rng = None
        
        if(config.get_dict_value(ssdict, config_keys.KEY_NFP_SS_TYPE) not in config_keys.allowed_symbolstypes): 
            raise ParseConfigError("\"%s\" is not allowed value for \"%s\"" % (dict[ config_keys.KEY_NFP_SS_TYPE ], config_keys.KEY_NFP_SS_TYPE))

        if(config.get_dict_value(ssdict, config_keys.KEY_NFP_SS_TYPE) == config_keys.KEY_NFP_SS_TYPE_RANGE):

            start = config.get_dict_value(ssdict, config_keys.KEY_NFP_SS_TYPE_RANGE_START)
            end = config.get_dict_value(ssdict, config_keys.KEY_NFP_SS_TYPE_RANGE_END)
            rng = range(start, end)
        
        if(config.get_dict_value(ssdict, config_keys.KEY_NFP_SS_TYPE) == config_keys.KEY_NFP_SS_TYPE_LIST):
            rng = config.get_dict_value(ssdict, config_keys.KEY_NFP_SS_TYPE_LIST_LIST)

        symbolSizeDict = config.get_dict_value(dict, config_keys.KEY_NFP_SYMBOLSIZE)

        return fontInfo(
                encoding=config.get_dict_value(dict, config_keys.KEY_NFP_ENCODING),
                type=type,
                id=id,
                size=config.get_dict_value(dict, config_keys.KEY_NFP_SIZE),
                sizeMode=dict[config_keys.KEY_NFP_SIZEMODE],
                positioning=dict[config_keys.KEY_NFP_POSITIONING],
                output=config.get_outputinfo(config.get_dict_value(dict, config_keys.KEY_NFP_OUTPUT)),
                symbols=rng,
                symbolSize=size(
                    width=config.get_dict_value(symbolSizeDict, config_keys.KEY_NFP_SYMBOLSIZE_W),
                    height=config.get_dict_value(symbolSizeDict, config_keys.KEY_NFP_SYMBOLSIZE_H)
                )
            )


    def __init__(self, nfp, action):
        self.nfp = nfp
        self.action = action

    @staticmethod
    def load(path):
        logger = logging.getLogger(__name__)

        try:
            with open(path, encoding="utf8") as f:

                input_str = removeComments(f.read().lower())

                data = json.loads(input_str)
                return config(
                        nfp=config.get_fontinfo( config.get_dict_value(data, config_keys.KEY_NFP)),
                        action=config.get_actioninfo( config.get_dict_value(data, config_keys.KEY_ACTION))
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
            config_keys.KEY_NFP : self.nfp.toJSON(),
            config_keys.KEY_ACTION : self.action.toJSON()
        }