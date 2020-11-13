#include <stdio.h>

// register int z = 10; // cannot be used in global scope outside of main

int main(void) {
    register int x;
    int y;

    // int *xptr = &x; // this will generate an error because you cannot access the address of the register
    register int *yptr = &y; // this will work because it stores the pointer into the register 


    for (x=1; x <= 15; x++) {
        printf("register x is : %d\n", x);
    }
    return 1;
}