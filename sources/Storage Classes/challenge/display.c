#include <stdio.h>

extern int counter;

void display() {
    printf("Your global variable incremented by 1 is %d\n", counter++);
}