BUILD_NAME=metronome

OS=LINUX

CC=
OP=3

PATH_SRC=./src/
PATH_OBJ=./obj/
PATH_LIB=./lib/
PATH_BIN=./bin/

SRC=main.c
OBJ=main.o

ifeq ($(OS),LINUX)
	LIB+=libraylib.so
	CC:=x86_64-linux-gnu-gcc
endif

ifeq ($(OS),WIN)
	LIB+=libraylib.dll
	CC:=x86_64-w64-mingw32-gcc
	BUILD_NAME:= $(addsuffix .exe,$(BUILD_NAME))
endif

FLAGS+=
CFLAGS+=-Wall -O$(OP)

SRC:= $(addprefix $(PATH_SRC),$(SRC) )
OBJ:= $(addprefix $(PATH_OBJ),$(OBJ) )
LIB:= $(addprefix $(PATH_LIB),$(LIB) )
BUILD_NAME_LN:=$(BUILD_NAME)
BUILD_NAME:= $(addprefix $(PATH_BIN),$(BUILD_NAME) )


$(BUILD_NAME) : $(OBJ)
	mkdir bin
	$(CC) -o $(BUILD_NAME) $(OBJ) $(LIB) $(FLAGS)
	ln -sf $(BUILD_NAME) $(BUILD_NAME_LN)

$(PATH_OBJ)%.o : $(PATH_SRC)%.c
	mkdir obj
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	rm $(BUILD_NAME) $(PATH_OBJ)*.o $(BUILD_NAME_LN)

