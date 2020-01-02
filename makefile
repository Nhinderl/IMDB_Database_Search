CC = gcc
CFLAGS = -Wall -pedantic -ansi

all: src/main.o src/common.o src/name.o src/title.o src/principals.o src/binary.o
	$(CC) $(CFLAGS) -o a3 src/main.o src/common.o src/name.o src/title.o src/principals.o src/binary.o

main.o: src/main.c src/name.h src/common.h src/title.h src/principals.h src/binary.h
	$(CC) $(CFLAGS) main.c -o a3

common.o: src/common.c src/common.h
	$(CC) $(CFLAGS) common.c -o common

name.o: src/name.c src/name.h src/common.h
	$(CC) $(CFLAGS) name.c -o name

title.o: src/title.c src/title.h src/common.h
	$(CC) $(CFLAGS) title.c -o title

principals.o: src/principals.c src/principals.h src/common.h
	$(CC) $(CFLAGS) principals.c -o principals

binary.o: src/binary.c src/binary.h src/name.h src/title.h src/principals.h src/common.h
	$(CC) $(CFLAGS) binary.c -o binary

clean:
	rm src/*.o