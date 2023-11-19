#outputFile = mem_test
CC = gcc
all: mem_test

mem_test: mem_test.c my_malloc.c
	$(CC) -g $^ -o $@

clean:
	rm -f mem_test *.o
