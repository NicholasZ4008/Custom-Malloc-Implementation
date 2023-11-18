#include "my_malloc.h"

MemoryBlock pool[POOL_SIZE];
//static List* free_block_list = NULL;

//Initialize blocks
void mem_init() {
    for (int i = 0; i < POOL_SIZE; i++) {
        pool[i].isFree = true;
    }
}


// void mem_init(size_t totalSize, size_t blockSize){
//     List* memoryPool = List_create();
//     // Divide totalSize by blockSize and initialize nodes
//     for (size_t i = 0; i < totalSize / blockSize; ++i) {
//         MemoryBlock* block = (MemoryBlock*)malloc(sizeof(MemoryBlock));
//         block->blockSize = blockSize;
//         block->isFree = true;
//         List_append(memoryPool, block);
//     }
//     return memoryPool;
// }


//Give memory space to block
void* my_malloc(size_t size) {
    if (size > BLOCK_SIZE) {
        return NULL; // Size request exceeds block size
    }

    for (int i = 0; i < POOL_SIZE; i++) {
        if (pool[i].isFree) {
            pool[i].isFree = false;
            return (void*)pool[i].data; // Return the address of the data segment
        }
    }

    return NULL; // No free block available
}


// Custom free function with coalescing adjacent free blocks
void my_free(void* block) {
    if (block == NULL) return; // No action if block is NULL

    // Iterate over the pool to find the corresponding block
    for (int i = 0; i < POOL_SIZE; i++) {
        if (pool[i].data == block) {
            pool[i].isFree = true;
            return;
        }
    }
}


//Free all allocated blocks of memory
void my_free_all(){

};

