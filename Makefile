CFLAGS = -Wall -pedantic

blinker: main.o blinker.o list.o file.o
	gcc $(CFLAGS) main.c blinker.c list.c file.c input.lib -o blinker

main.o: main.c blinker.h input.h
	gcc $(CFLAGS) -c main.c -o main.o

blinker.o: blinker.c blinker.h input.h
	gcc $(CFLAGS) -c blinker.c -o blinker.o

list.o: list.c blinker.h
	gcc $(CFLAGS) -c list.c -o list.o

file.o: file.c blinker.h
	gcc $(CFLAGS) -c file.c -o file.o

input.o: input.lib
	gcc $(CFLAGS) -c input.lib -o input.o