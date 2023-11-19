/*Header class for custom malloc and free*/
#include "stdlib.h"
#include "stdbool.h"

#define MEMORY_POOL_SIZE 1024
#define BLOCK_SIZE 128
#define POOL_SIZE (MEMORY_POOL_SIZE / BLOCK_SIZE) //Want a pool size of atleast 100

typedef struct {
    char data[BLOCK_SIZE];
    bool isFree;
    size_t size; // New field to store the size of the allocated block
} MemoryBlock;

// MemoryBlock pool[POOL_SIZE];

//Initialize list of all blocks with linked list
void mem_init();
//Give memory space to block
void* my_malloc(size_t size);
//Free 1 block of memory
void my_free(void* block);
