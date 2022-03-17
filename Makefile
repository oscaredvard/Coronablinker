# Variables
CFLAGS = -Wall -pedantic
RM = del
BIN = blinker.exe blinkertest.exe listtest.exe filetest.exe
OBJ = main.o blinker.o list.o file.o date.o
TESTOBJ = blinkertest.o listtest.o filetest.o

# Object files

blinker.o: blinker.c blinker.h input.h
	gcc $(CFLAGS) -c blinker.c -o blinker.o

blinkertest.o: blinkertest.c blinker.h input.h
	gcc $(CFLAGS) -c blinkertest.c -o blinkertest.o

date.o: date.c blinker.h
	gcc $(CFLAGS) -c date.c -o date.o

datetest.o: datetest.c blinker.h
	gcc $(CFLAGS) -c datetest.c -o datetest.o

file.o: file.c blinker.h
	gcc $(CFLAGS) -c file.c -o file.o

filetest.o: filetest.c blinker.h
	gcc $(CFLAGS) -c filetest.c -o filetest.o

input.o: input.lib
	gcc $(CFLAGS) -c input.lib -o input.o

list.o: list.c blinker.h
	gcc $(CFLAGS) -c list.c -o list.o

listtest.o: listtest.c blinker.h
	gcc $(CFLAGS) -c listtest.c -o listtest.o

main.o: main.c blinker.h input.h
	gcc $(CFLAGS) -c main.c -o main.o

# Executable files

blinker: main.o blinker.o list.o date.o file.o
	gcc $(CFLAGS) main.c blinker.c list.c date.c file.c input.lib -o blinker

blinkertest: blinkertest.o blinker.o
	gcc $(CFLAGS) blinkertest.c blinker.c input.lib -o blinkertest

listtest: listtest.o list.o
	gcc $(CFLAGS) listtest.c list.c -o listtest

filetest: filetest.o file.o date.o
	gcc $(CFLAGS) filetest.c file.c date.c -o filetest

datetest: datetest.o date.o
	gcc $(CFLAGS) datetest.c date.c -o datetest

test: blinkertest.o listtest.o filetest.o
	gcc $(CFLAGS) blinkertest.o blinker.o input.lib -o blinkertest
	gcc $(CFLAGS) listtest.o list.c input.lib -o listtest
	gcc $(CFLAGS) filetest.o file.c date.o input.lib -o filetest

runtest: blinkertest listtest filetest
	.\blinkertest.exe
	.\listtest.exe
	.\filetest.exe

all: blinker blinkertest listtest filetest

clean:
	$(RM) $(BIN) $(OBJ) $(TESTOBJ)