import json
import logging

class ParseConfigError(Exception):
    def __init__(self, message):
        super.__init__()
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
                width=dict["width"],
                height=dict["height"]
            )

    def toJSON(self):
        return {
            "width" : self.height,
            "height" : self.height
        }

class config:
    
    @staticmethod
    def get_dict_value(dict, key):
        if(key in dict): return dict[key]
        else: raise ParseConfigError("Unable to find key \"%s\" in dictionary" % key)

    @staticmethod
    def get_symbol_list(dict):
        if("type" not in dict): raise ParseConfigError("\"Symbols\" dictionary have to contain \"type\" section")
        if(dict["type"] not in ["list", "range"]): raise ParseConfigError("\"%s\" is not allowed value" % dict["type"])

        if(dict["type"] == "range"):
            start = config.get_dict_value(dict, "start")
            end = config.get_dict_value(dict, "end")
            return range(start, end)
        
        elif(dict["type"] == "list"):
            return config.get_dict_value(dict, "list")

    def __init__(self, fontName = "Courier", fontEncoding = "unicode",  symbols = {}, symbolSize = size(20, 10)):
        self.fontName = fontEncoding
        self.fontEncoding = fontEncoding
        self.symbols = symbols
        self.symbolSize = symbolSize

    @staticmethod
    def load(path):
        logger = logging.getLogger(__name__)

        try:
            with open(path) as f:
                data = json.load(f)
                return config(
                        fontName=config.get_dict_value(data, "fontName"),   
                        fontEncoding=config.get_dict_value(data, "fontEncoding"),   
                        symbols=config.get_dict_value(data, "symbols"),   
                        symbolSize=size.parse_from_dict(config.get_dict_value(data, "symbolSize"))
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
            "fontName" : self.fontName,
            "fontEncoding" : self.fontEncoding,
            "symbols" : self.symbols,
            "symbolSize" : self.symbolSize.toJSON()
        }