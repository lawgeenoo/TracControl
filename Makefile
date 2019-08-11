CC = gcc
CFLAGS = -Wall -w
	
SRC := $(wildcard src/*.c)
INC := -Iinc

all: say_make program say_done

say_make:
	@echo "Building"

program:	
	@$(CC) $(CFLAGS) $(INC) $(SRC)  -o exe

say_done:
	@echo "Done"

