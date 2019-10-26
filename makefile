all: main.o functions.o
	gcc -o program main.o functions.o

main.o: main.c headers.h
	gcc -c main.c

functions.o: functions.c headers.h
	gcc -c functions.c

run:
	./program
debug: main.c functions.c headers.h
	gcc -g main.c functions.c
gdb:
	gdb a.out
