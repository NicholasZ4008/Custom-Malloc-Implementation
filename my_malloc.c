#include "my_malloc.h"
#include <stdio.h>

MemoryBlock pool[POOL_SIZE];

//Initialize blocks
void mem_init() {
    for (int i = 0; i < POOL_SIZE; i++) {
        pool[i].isFree = true;
    }
}

//Search for free block or blocks to determine which to use
void* binarySearch(int left, int right, size_t numBlocks) {

    // No consecutive free blocks available
    if (left > right) {
        return NULL; 
    }
    //Initialize middle
    int mid = left + (right - left) / 2;

    // Check if the current block and the next 'numBlocks - 1' blocks are free
    for (int i = 0; i < numBlocks; i++) {
        //numBlocks - 1 is not free
        if (!pool[mid + i].isFree) {
            // Move to the right half of the array from the last occupied block
            return binarySearch(mid + i + 1, right, numBlocks);
        }
    }

    // Check if the previous block from mid is free
    if (mid > 0 && pool[mid - 1].isFree) {
        // Move to the left half of the array
        return binarySearch(left, mid - 1, numBlocks);
    }

    // Found a consecutive block which is available
    for (int i = 0; i < numBlocks; i++) {
        pool[mid + i].isFree = false;
        pool[mid + i].size = numBlocks; // Store the size of the allocated block
    }

    return (void*)pool[mid].data;
}
// Function to allocate memory using binary search
void* my_malloc(size_t size) {
    // Check for correct size
    if(size <= 0){
        return NULL;
    }

    // Size will take up multiple blocks
    if (size > BLOCK_SIZE) {
        // Allocate multiple blocks if size exceeds BLOCK_SIZE
        size_t numBlocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
        return binarySearch(0, POOL_SIZE - numBlocks, numBlocks);
    }

    // Allocate a single block
    return binarySearch(0, POOL_SIZE - 1, 1);
}

// Free memory block
void my_free(void* block) {
    if (block == NULL){
        return;
    }        

    // Find the block index
    int index = ((char*)block - (char*)pool) / sizeof(MemoryBlock);

    // Mark the block as free
    pool[index].isFree = true;
}
