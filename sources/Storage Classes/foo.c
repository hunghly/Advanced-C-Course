#include <stdio.h>

extern int count;

int foo() {
    extern int i; // you cannot change it in the declaration
    i = 100; // you can change the external var here
    extern char text[]; // it is already declared in extern-var.c so do not need to initialize with array size
    printf("my external var is %d\n", i);
    return i;
}

void write_extern(void) {
    printf("count is %d\n", count);
}