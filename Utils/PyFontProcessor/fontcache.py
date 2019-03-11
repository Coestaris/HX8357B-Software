import json

import helpers

KEY_NULLCHAR = "nullchar"
KEY_CHARDICT = "chardict"
KEY_CHARSIZE = "charsize"
KEY_IMAGESPERROW = "imagesperrow"
class fontcache:

    def __init__(self, nullChar, charDict, charSize, imagesPerRow):
        self.nullChar = nullChar
        self.charSize = charSize
        self.imagesPerRow = imagesPerRow

        self.charDict = dict()
        for k, v in charDict.items():
            self.charDict.update( { int(k) : v } )

    @staticmethod
    def load(fname):
        with open(fname, encoding="utf8") as f:
            input_str = helpers.removeComments(f.read().lower())
            data = json.loads(input_str) 
            return fontcache(
                nullChar=data[ KEY_NULLCHAR ],
                charDict=data[ KEY_CHARDICT ],
                charSize=data[ KEY_CHARSIZE ],
                imagesPerRow=data[ KEY_IMAGESPERROW ]
            )

    def save(self, fname):
        dict = {
            KEY_CHARDICT : self.charDict,
            KEY_CHARSIZE : self.charSize,
            KEY_NULLCHAR : self.nullChar,
            KEY_IMAGESPERROW : self.imagesPerRow
        }
        
        with open(fname, mode="w", encoding="utf8") as f:
            json.dump(dict, f, sort_keys=True)