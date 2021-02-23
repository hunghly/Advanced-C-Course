// you cannot assign one array to another, so often programmers use loops to copy one array to another, element by element
// - the only exception is strcpy and strncpy to copy char arrays
// the memcpy and memmove functions offers the same convenience for other array types
// void* memcpy( void *dest, const void *src, size_t count );
// void* memcpy( void *restrict dest, const void *restrict src, size_t count );
// void* memmove( void* dest, const void* src, size_t count );

// both of these functions copy n bytes from the src to the destination and both returns the value of dst
// the difference is with memcpy, you have restrict type qualifier
// with memcpy, it is free to assume that there is no overlap between the two memory ranges
// with memmove, copying takes place as if all the bytes are first copied to a temp buffer before being copied to the final destinatin

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 5


int main(void) {
    int values[SIZE] = {1,2,3,4,5};
    int target[SIZE];
    memcpy(target, values, sizeof(int) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", target[i]);
    }
    return 0;
}