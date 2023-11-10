/*Header class for custom malloc and free*/
#include <stdlib.h>
#include <stdbool.h>

//Treat as a tree
typedef struct Block{
    size_t size; // Size of block to add
    bool isFree; // Is this block available. Only temporary. Not sure if we will keep it
    struct Block* right; // Right child
    struct Block* left; // Left child
} Block;

void* my_malloc(size_t size);
void my_free(void* block);