#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int count, ...);

int main(void) {

    // write a program that creates a fariadic function that will allow a programmer to add any amount of ints
    // that they would like to add together
    // use the first argument as number of arguments;

    printf("The sum of 11, 23, 55, 432, 121 is %d\n", sum(5, 11, 23, 55, 432, 121));
    printf("The sum of 1,2,3,4,5,6,7,8,9,10,11,12 is %d\n", sum(12, 1,2,3,4,5,6,7,8,9,10,11,12));
}

int sum(int count, ...) {

    va_list pargs; // initialize the variable length function
    va_start(pargs, count); // specify the last fixed parameter to start from
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += va_arg(pargs, int); // get each arg
    }
    va_end(pargs); // end the list and clean up
    return sum;
}