/*
    Test cases for custom implementation of malloc and free
*/

#include "my_malloc.h"
#include <stdio.h>
#include <assert.h>

void test_basic_allocation_deallocation() {
    mem_init();
    void* ptr = my_malloc(64);
    printf("Allocated single block at address: %p\n", ptr);
    assert(ptr != NULL);
    my_free(ptr);
    // Verify that the block is marked as free
}

void test_allocating_multiple_blocks() {
    // mem_init();
    void* ptr1 = my_malloc(64);
    printf("Allocated first block at address: %p\n", ptr1);
    void* ptr2 = my_malloc(64);
    printf("Allocated second block at address: %p\n", ptr2);

    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    // Check if ptr1 and ptr2 are not NULL and consecutive
    my_free(ptr1);
    my_free(ptr2);
    assert(ptr1 == NULL);
    assert(ptr2 == NULL);
    // Verify that the blocks are marked as free
}

void test_allocating_large_memory() {
    // mem_init();
    void* largePtr = my_malloc(300);
    printf("Allocated large block at address: %p\n", largePtr);

    assert(largePtr != NULL);
    // Check if largePtr is not NULL and spans multiple consecutive blocks
    my_free(largePtr);
    // Verify that the blocks are marked as free
}

void test_coalescing() {
    // mem_init();
    void* ptr1 = my_malloc(64);
    void* ptr2 = my_malloc(64);
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    my_free(ptr1);
    my_free(ptr2);
    // Verify that the freed blocks are coalesced into a larger free block
}

void test_edge_cases() {
    mem_init(); //Free all nodes and pointers before it
    void* fullPool = my_malloc(MEMORY_POOL_SIZE);
    assert(fullPool != NULL);
    // Check if fullPool is not NULL
    my_free(fullPool);
    // Verify that the entire pool is marked as free

    void* tooLarge = my_malloc(MEMORY_POOL_SIZE + 1);
    assert(tooLarge == NULL);
    // Check if tooLarge is NULL
}

void test_stress_testing() {
    // mem_init();
    for (int i = 0; i < 1000; i++) {
        void* ptr = my_malloc(300);
        // Perform operations with the allocated memory
        my_free(ptr);
    }
    // Verify that there are no memory leaks or fragmentation issues
}

int main() {
    // Run the test cases
    test_basic_allocation_deallocation();
    test_allocating_multiple_blocks();
    test_allocating_large_memory();
    test_coalescing();
    test_edge_cases();
    test_stress_testing();

    printf("All tests passed!\n");

    return 0;
}
