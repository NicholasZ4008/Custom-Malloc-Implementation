/*
    Test cases for custom implementation of malloc and free
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_malloc.h"

int main(){
    mem_init();

    int* intPtr = (int*)my_malloc(sizeof(int));
    *intPtr = 42;

    char* charPtr = (char*)my_malloc(10 * sizeof(char));
    strcpy(charPtr, "Hello!");
    
    printf("int: %d\n", *intPtr);
    printf("string: %s\n", charPtr);

    // Free allocated memory
    my_free(intPtr);
    my_free(charPtr);

    return 0;
}