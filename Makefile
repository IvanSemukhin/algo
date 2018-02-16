CC=g++
CFLAGS=-c -Wall -std=c++11 -O3

all: algo

algo: main.o func.o
	$(CC) main.o func.o -o algo

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

func.o: func.cpp
	$(CC) $(CFLAGS) func.cpp

clean:
	rm -rf *.o algo
