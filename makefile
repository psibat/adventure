CC=gcc
CFLAGS=-Wall
DEPS = helpers.h constants.h draw.h parser.h game.h
OBJ = draw.o parser.o game.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
