import json

import helpers

KEY_NULLCHAR = "nullchar"
KEY_CHARDICT = "chardict"
KEY_CHARSIZE = "charsize"

class fontcache:

    def __init__(self, nullChar, charDict, charSize):
        self.nullChar = nullChar
        self.charDict = charDict
        self.charSize = charSize

    @staticmethod
    def load(fname):
        with open(fname, encoding="utf8") as f:
            input_str = helpers.removeComments(f.read().lower())
            data = json.loads(input_str) 
            return fontcache(
                nullChar=data["nullchar"],
                charDict=data["chardict"],
                charSize=data["charsize"],
            )

    def save(self, fname):
        dict = {
            KEY_CHARDICT : self.charDict,
            KEY_CHARSIZE : self.charSize,
            KEY_NULLCHAR : self.nullChar
        }
        
        with open(fname, mode="w", encoding="utf8") as f:
            json.dump(dict, f)