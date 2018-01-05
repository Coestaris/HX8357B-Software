#Result font name
NAME = sevenSegmentDigits

#Max width of symbol
WIDTH = 100

#Max height of symbol
HEIGHT = 100

#Font size
FSIZE = 16

#Use RLE compression
ENCODING = true

#How many bytes will be in row
MAX_BYTES_IN_ROW = 10

#Start char of new font
MINCHAR = 32

#End char of new font
MAXCHAR = 127

#Default char for unrecognised chars. Usually 63 ('?')
EMPTY_CHAR_INDEX = 63

#Base font name
FONT = Monospace_Regular

#Output results while rendering
SAVE_IMAGES = true

#Output rendering result name format
SAVE_IMAGES_NAMEFORMAT = img/{0}.png

#Save general image of rendering result
SAVE_TOTAL_IMAGE = true

#Draw border on general image
SAVE_TOTAL_IMAGE_BORDERS = true

#General rendering result image name format
SAVE_TOTAL_IMAGE_NAMEFORMAT = img/_img_.bmp

#Images per row in general image
SAVE_TOTAL_IMAGE_IMGPEROW = 20

FLAGS  = -name:$(NAME)
FLAGS += -w:$(WIDTH)
FLAGS += -h:$(HEIGHT)
FLAGS += -fsize:$(FSIZE)
FLAGS += -Format_MaxBytes:$(MAX_BYTES_IN_ROW)
FLAGS += -minchar:$(MINCHAR)
FLAGS += -maxchar:$(MAXCHAR)
FLAGS += -EmptyCharIndex:$(EMPTY_CHAR_INDEX)
FLAGS += -font:$(FONT)
FLAGS += -saveimages:$(SAVE_IMAGES)
FLAGS += -OutputImagesFormat:$(SAVE_IMAGES_NAMEFORMAT)
FLAGS += -SaveTotalImage:$(SAVE_TOTAL_IMAGE)
FLAGS += -TotalImageBorders:$(SAVE_TOTAL_IMAGE_BORDERS)
FLAGS += -OutputTotalImageFormat:$(SAVE_TOTAL_IMAGE_NAMEFORMAT)
FLAGS += -TotalImagePerRow:$(SAVE_TOTAL_IMAGE_IMGPEROW)
FLAGS += -Encoding:$(ENCODING)

PROGRAM = ./FontRasterer.exe

IMAGE_DIRECTORY = img

BACKUPNAME = backup.tar.save

backup:
	$(shell tar -czf $(BACKUPNAME) $(IMAGE_DIRECTORY)/)

restore:
	$(shell tar -xzvf $(BACKUPNAME))

save:
	$(PROGRAM) -mode:0 $(FLAGS)

rast:
	$(PROGRAM) -mode:1 $(FLAGS)

full:
	$(PROGRAM) -mode:2 $(FLAGS)

clean:
	$(shell rm -f $(IMAGE_DIRECTORY)/*)

savetotal:
	$(PROGRAM) -mode:3 $(FLAGS)
