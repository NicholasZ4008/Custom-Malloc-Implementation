/*Header class for custom malloc and free*/
#include <stdlib.h>
#include <stdbool.h>
// #include "LinkedList/list.h"

#define MEMORY_POOL_SIZE 1024
#define BLOCK_SIZE 128 // Size of each block
#define POOL_SIZE (MEMORY_POOL_SIZE/BLOCK_SIZE) // Total number of blocks in the pool

typedef struct {
    char data[BLOCK_SIZE]; // Memory space
    bool isFree;           // Indicates if the block is free
} MemoryBlock;

//Initialize list of all blocks with linked list
void mem_init();
//Give memory space to block
void* my_malloc(size_t size);
//Free 1 block of memory
void my_free(void* block);
