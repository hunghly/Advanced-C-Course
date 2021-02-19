#include <stdio.h>
#include <stdlib.h>

void allocateMemory(int **ptr) {
    // printf("ptr is %s\n", ptr);
    *ptr = (int*) malloc(sizeof(int));
}


int main(void) {
    // create function called allocate memory that takes a single int ptr
    // it should allocate memory for the ptr

    // create a main function that:
    // creates an int ptr and initialize to null
    // calls allocatememory function and pass in ptr
    // assign a value to the int ptr that is pointing to (de-reference)
    // print the value of what the ptr is pointing to
    // free ptr

    int *x = NULL;
    // int y = 10;
    allocateMemory(&x);
    *x = 20;
    printf("X is %d\n", *x);
    free(x);

    return 0;
}