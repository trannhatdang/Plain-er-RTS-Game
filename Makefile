SRC:= src
OBJ:= obj
INC:= include
CFLAGS:= -Wall -I ./include -L ./src -lraylib -lopengl32 -lgdi32 -lwinmm
SOURCES:= $(SRC)/*.c
INCLUDES:= $(subst $(SRC), $(INC), $(patsubst %.c, %.h, $(SOURCES)))
OBJECTS:= $(subst $(SRC), $(OBJ), $(patsubst %.c, %.o, $(SOURCES)))
OUTPUT:= game.exe

game.exe: $(SOURCES) $(INCLUDES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

clean: 
	rm -f *.c *.o all
