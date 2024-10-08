TARGET=metronome
CC=gcc
MKDIR=mkdir -p

BIN_PATH = ./bin/
SRC_PATH = ./src/
OBJ_PATH = ./obj/

SRC = $(shell find $(SRC_PATH) -type f -name '*.c')
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o,$(SRC))

CFLAGS+= -g -O2 $(shell pkg-config --cflags gtk4)
LDFLAGS+= $(shell pkg-config --libs gtk4)

.PHONY: all clean

all: $(BIN_PATH)$(TARGET)

$(BIN_PATH)$(TARGET): $(OBJ)
	$(MKDIR) $(@D)
	$(CC) -o $@ $(LDFLAGS) $(CFLAGS) $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(MKDIR) $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm $(BIN_PATH)$(TARGET)
>>>>>>> cda9330 (new start)
