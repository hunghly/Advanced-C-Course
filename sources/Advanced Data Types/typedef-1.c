#include <stdio.h>

typedef int* i_pointer;
typedef int NUM;

// #define peach int // defines peach as an int

#define int_pointer int *

int_pointer chalk, cheese; // same as int *chalk, cheese; only chalk is a int pointer

// unsigned peach i;

typedef int banana; //defines a new int name as banana

// unsigned banana i; error here

typedef char* char_ptr;

char_ptr Bently, Rolls_Royce; // both are char*'s

int main() {
    i_pointer p; // same as int *p;

    i_pointer a, *b; //same as int *p, **b

    i_pointer myArray[10]; // 10 int *'s
    
    NUM x = 10;

    int y = 15;

    printf("%d\n", x);
    printf("%d\n", y);


    return 0;
}