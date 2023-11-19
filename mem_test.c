/*
    Test cases for custom implementation of malloc and free
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "my_malloc.h"

void test_basic_allocation_deallocation() {
    size_t block = 64;
    printf("Basic allocation of 1 block of %ld bytes:\n", block);
    void* ptr = my_malloc(block);
    printf("Allocated single block at address: %p\n", ptr);
    assert(ptr != NULL);
    my_free(ptr);
    printf("\n\n");
}

void test_allocating_multiple_blocks() {
    size_t block = 64;
    printf("Basic allocation of 2 block of %ld bytes:\n", block);
    void* ptr1 = my_malloc(block);
    printf("Allocated first block at address: %p\n", ptr1);
    void* ptr2 = my_malloc(block);
    printf("Allocated second block at address: %p\n", ptr2);

    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    my_free(ptr1);
    my_free(ptr2);
    printf("\n\n");
}

void test_allocating_large_memory() {
    size_t block = 300;
    printf("Allocation of 2 large blocks of %ld bytes\n", block);
    void* largePtr = my_malloc(block);
    printf("Allocated large block at address: %p\n", largePtr);
    void* largePtr2 = my_malloc(block);
    printf("Allocated large block at address: %p\n", largePtr2);

    assert(largePtr != NULL);
    assert(largePtr2 != NULL);
    my_free(largePtr);
    my_free(largePtr2);
    printf("\n\n");
}

void test_edge_cases() {
    size_t block = MEMORY_POOL_SIZE;
    printf("Allocate max size: %ld\n", block);

    mem_init();
    void* fullPool = my_malloc(block);
    assert(fullPool != NULL);
    my_free(fullPool);

    printf("Allocate max size + 1, assert returns null\n");
    void* tooLarge = my_malloc(MEMORY_POOL_SIZE + 1);
    assert(tooLarge == NULL);
    printf("\n\n");
}

void test_allocate_strings() {
    printf("Allocate for strings:\n");
    size_t strLength = 10;
    printf("Allocate string of size: %ld*sizeof(char)\n", strLength);
    mem_init();
    char* strPtr = my_malloc(strLength * sizeof(char));

    assert(strPtr != NULL);

    strcpy(strPtr, "Hello!");
    printf("Able to do strcpy for: %s\n", strPtr);

    my_free(strPtr);
    printf("\n\n");
}

void test_allocate_integers() {
    printf("Allocate for integers:\n");
    size_t block = 3;
    printf("Allocate for int size: %ld*sizeof(int)\n", block);
    mem_init();

    int* intPtr = my_malloc(block * sizeof(int));

    assert(intPtr != NULL);

    intPtr[0] = 42;
    intPtr[1] = 123;
    intPtr[2] = -7;

    printf("Allocated integers: %d, %d, %d\n", intPtr[0], intPtr[1], intPtr[2]);

    my_free(intPtr);
    printf("\n\n");
}

void test_mixed_allocation() {
    printf("Allocate for both strings and integers\n");
    size_t int_block = 2;
    printf("Int allocation: %ld*sizeof(int)\n", int_block);
    size_t str_block = 20;
    printf("Allocation of string: %ld*sizeof(char)\n", str_block);
    int* intPtr = my_malloc(int_block * sizeof(int));
    char* strPtr = my_malloc(str_block * sizeof(char));

    assert(intPtr != NULL);
    assert(strPtr != NULL);

    intPtr[0] = 99;
    intPtr[1] = -5;

    strcpy(strPtr, "Mixed Allocation!");

    printf("Allocated integers: %d, %d\n", intPtr[0], intPtr[1]);
    printf("Allocated string: %s\n", strPtr);

    my_free(intPtr);
    my_free(strPtr);
    printf("\n\n");
}

void test_stress_testing() {
    size_t iterations = 1000;
    size_t block = 300;
    printf("Stress test of %ld blocks with size %ld\n", iterations, block);
    mem_init();
    for (int i = 0; i < iterations; i++) {
        void* ptr = my_malloc(block);
        my_free(ptr);
    }
    printf("\n\n");
}

int main() {
    mem_init();
    test_basic_allocation_deallocation();
    test_allocating_multiple_blocks();
    test_allocating_large_memory();
    test_edge_cases();
    test_allocate_strings();
    test_allocate_integers();
    test_mixed_allocation();
    test_stress_testing();


    printf("All tests passed!\n");

    return 0;
}
