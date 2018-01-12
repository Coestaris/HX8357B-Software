#Output bitmap name
NAME = sheep

#Width of image
WIDTH = 128

#Height of image
HEIGHT = 128

#Generate .h file
HFile = true

SIZEMODE = Stretch
#SIZEMODE = Truncate

#Outout color model of bitmap
COLORMODE = Color_565
COLORMODE = Color_555
COLORMODE = Color_332
#COLORMODE = GrayScale
#COLORMODE = GrayScale_encoded
#COLORMODE = Binary
#COLORMODE = Binary_encoded
#COLORMODE = Default

#Input bitmap NAME
BITRMAPNAME = image.png

#How many bytes will be in row
MAX_BYTES_IN_ROW = 10

FLAGS  = name:$(NAME)
FLAGS += W:$(WIDTH)
FLAGS += H:$(HEIGHT)
FLAGS += HFile:$(HFile)
FLAGS += SizeMode:$(SIZEMODE)
FLAGS += ColorMode:$(COLORMODE)
FLAGS += BitmapName:$(BITRMAPNAME)
FLAGS += Format_MaxBytes:$(MAX_BYTES_IN_ROW)

PROGRAM = ./FontRasterer.exe

full:
	$(PROGRAM) $(FLAGS)
