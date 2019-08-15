CC = gcc
INC = -Iinc
BIN_DIR = bin
SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))  
EXEC := tc
CLEAN := rm -rf $(OBJ_DIR) $(BIN_DIR) tc

all: tc 

tc: $(OBJ_FILES)
	@$(CC) -o $@ $(OBJ_FILES) 
	@mv $(EXEC) $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(INC) -c -o $@ $<
	
.PHONY: clean
clean:
	@$(CLEAN)

