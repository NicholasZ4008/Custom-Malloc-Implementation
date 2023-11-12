/*Header class for custom malloc and free*/
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList/list.h"

#define MEMORY_POOL_SIZE 1024

//Initialize list of all blocks with linked list
void my_malloc_init();

//Give memory space to block
void* my_malloc(size_t size);
//Free 1 block of memory
void my_free(void* block);
//Free all allocated blocks of memory
void my_free_all();