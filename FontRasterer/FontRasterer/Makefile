PROGRAM = ./FontRasterer.exe


#Result font name
NAME = std

#Max width of symbol
WIDTH = 10

#Max height of symbol
HEIGHT = 10

#Font size
FSIZE = 16

#How many bytes will be in row
MAX_BYTES_IN_ROW = 10

#

full: rast save

save:
	$(PROGRAM) -mode:0 $(FLAGS)

rast:
	$(PROGRAM) -mode:1 $(FLAGS)
