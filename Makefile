CC = gcc
CFLAGS = -Wall -std=c99 
OBJECTS = main.o stack.o

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) main.o stack.o -o main

main.o : main.c stack.h
	$(CC) $(CFLAGS) -c main.c 

stack.o : stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c	

clean:
	rm *.o main
