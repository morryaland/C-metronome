BUILD_NAME=metronome

OS=LINUX

CC=gcc
OP=3

PATH_SRC=./src/
PATH_OBJ=./obj/
PATH_LIB=./lib/
PATH_BIN=./bin/

SRC=main.c window.c UI.c log.c
OBJ=main.o window.o UI.o log.o

ifeq ($(OS),WIN)
	BUILD_NAME:= $(addsuffix .exe,$(BUILD_NAME))
endif

FLAGS+=-lSDL2
CFLAGS+=-Wall -O$(OP) -Wcomment

SRC:= $(addprefix $(PATH_SRC),$(SRC) )
OBJ:= $(addprefix $(PATH_OBJ),$(OBJ) )
LIB:= $(addprefix $(PATH_LIB),$(LIB) )
BUILD_NAME_LN:=$(BUILD_NAME)
BUILD_NAME:= $(addprefix $(PATH_BIN),$(BUILD_NAME) )


$(BUILD_NAME) : $(OBJ)
	$(CC) -o $(BUILD_NAME) $(OBJ) $(LIB) $(FLAGS)
	ln -sf $(BUILD_NAME) $(BUILD_NAME_LN)

$(PATH_OBJ)%.o : $(PATH_SRC)%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	rm $(BUILD_NAME) $(PATH_OBJ)*.o $(BUILD_NAME_LN)
