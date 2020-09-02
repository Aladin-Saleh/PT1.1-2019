CC=gcc
CFLAGS=-ansi \
	   -lgraph
DEPS= snake.h 

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


snake: snake.o fonction.o
	$(CC) -o snake snake.o fonction.o -lgraph

clean: 
	rm -rf *.o


cleanall: clean
	rm -rf snake

run : snake
	./snake 