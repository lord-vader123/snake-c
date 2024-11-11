CC = gcc
CFLAGS = -g -Wall

game: main.o snake.o render.o utils.o
	$(CC) $(CFLAGS) -o game main.o snake.o render.o utils.o

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

snake.o: snake.c game.h
	$(CC) $(CFLAGS) -c snake.c

render.o: render.c game.h
	$(CC) $(CFLAGS) -c render.c

utils.o: utils.c game.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f ./*.o
