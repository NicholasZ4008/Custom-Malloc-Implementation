#outputFile = program
CC = gcc
all: program

program: mem_test.c my_malloc.c
	$(CC) -g $^ -o $@
# program: my_malloc.o mem_test.o
# 	gcc -Wall -Werror -o program my_malloc.o mem_test.o

# list.o: my_malloc.c my_malloc.h
# 	gcc -Wall -Werror -c my_malloc.c

# main.o: mem_test.c my_malloc.h
# 	gcc -Wall -Werror -c mem_test.c

clean:
	rm -f program *.o
