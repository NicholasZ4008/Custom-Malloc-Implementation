/*Header class for custom malloc and free*/
#include "stdlib.h"
#include "stdbool.h"

#define MEMORY_POOL_SIZE 4096
#define BLOCK_SIZE 128
#define POOL_SIZE (MEMORY_POOL_SIZE / BLOCK_SIZE)

typedef struct {
    char data[BLOCK_SIZE];
    bool isFree;
    size_t size; // store the size of the allocated block
} MemoryBlock;

//Initialize all blocks
void mem_init();

//Give memory space to block
void* my_malloc(size_t size);

//Free the pointer passed in of memory
void my_free(void* block);
