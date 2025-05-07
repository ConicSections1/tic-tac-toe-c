CC=gcc
CFLAGS=-Iinclude -Wall
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
EXEC=tictactoe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)
