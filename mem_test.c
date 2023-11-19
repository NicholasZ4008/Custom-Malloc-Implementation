/*
    Test cases for custom implementation of malloc and free
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "my_malloc.h"

void test_basic_allocation_deallocation() {
    void* ptr = my_malloc(64);
    printf("Allocated single block at address: %p\n", ptr);
    assert(ptr != NULL);
    my_free(ptr);
}

void test_allocating_multiple_blocks() {
    void* ptr1 = my_malloc(64);
    printf("Allocated first block at address: %p\n", ptr1);
    void* ptr2 = my_malloc(64);
    printf("Allocated second block at address: %p\n", ptr2);

    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    my_free(ptr1);
    my_free(ptr2);
}

void test_allocating_large_memory() {
    void* largePtr = my_malloc(300);
    printf("Allocated large block at address: %p\n", largePtr);
    void* largePtr2 = my_malloc(300);
    printf("Allocated large block at address: %p\n", largePtr2);

    assert(largePtr != NULL);
    assert(largePtr2 != NULL);
    my_free(largePtr);
    my_free(largePtr2);
}

void test_coalescing() {
    void* ptr1 = my_malloc(64);
    void* ptr2 = my_malloc(64);
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    my_free(ptr1);
    my_free(ptr2);
}

void test_edge_cases() {
    mem_init();
    void* fullPool = my_malloc(MEMORY_POOL_SIZE);
    assert(fullPool != NULL);
    my_free(fullPool);

    void* tooLarge = my_malloc(MEMORY_POOL_SIZE + 1);
    assert(tooLarge == NULL);
}

void test_stress_testing() {
    mem_init();
    for (int i = 0; i < 1000; i++) {
        void* ptr = my_malloc(300);
        my_free(ptr);
    }
}

void test_allocate_strings() {
    mem_init();
    char* strPtr = my_malloc(10 * sizeof(char));

    assert(strPtr != NULL);

    strcpy(strPtr, "Hello!");
    printf("Allocated string: %s\n", strPtr);

    my_free(strPtr);
}

void test_allocate_integers() {
    mem_init();

    int* intPtr = my_malloc(3 * sizeof(int));

    assert(intPtr != NULL);

    intPtr[0] = 42;
    intPtr[1] = 123;
    intPtr[2] = -7;

    printf("Allocated integers: %d, %d, %d\n", intPtr[0], intPtr[1], intPtr[2]);

    my_free(intPtr);
}

void test_mixed_allocation() {
    int* intPtr = my_malloc(2 * sizeof(int));
    char* strPtr = my_malloc(20 * sizeof(char));

    assert(intPtr != NULL);
    assert(strPtr != NULL);

    intPtr[0] = 99;
    intPtr[1] = -5;

    strcpy(strPtr, "Mixed Allocation!");

    printf("Allocated integers: %d, %d\n", intPtr[0], intPtr[1]);
    printf("Allocated string: %s\n", strPtr);

    my_free(intPtr);
    my_free(strPtr);
}

int main() {
    mem_init();
    test_basic_allocation_deallocation();
    test_allocating_multiple_blocks();
    test_allocating_large_memory();
    test_coalescing();
    test_edge_cases();
    test_allocate_strings();
    test_allocate_integers();
    test_mixed_allocation();
    test_stress_testing();


    printf("All tests passed!\n");

    return 0;
}
