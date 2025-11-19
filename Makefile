SRC:= ./src
OBJ:= ./obj
INCLUDE:= ./include
CFLAGS:= -Wall -I ./include -L ./src -lraylib -lopengl32 -lgdi32 -lwinmm
OBJECTS:= $(OBJ)/screen.o $(OBJ)/unit.o $(OBJ)/main.o
OUTPUT:= game.exe

$(OUTPUT): $(OBJECTS)
	$(CC) $^ $(CFLAGS) -o $@

$(OBJECTS): $(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $^ $(CFLAGS) -o $@

clean: 
	rm -f *.c *.o all
