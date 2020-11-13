#include <stdio.h>

int fun() {
    static int count = 0; // does not change when function exits
    int localvar = 0;
    printf("auto: %d, static:%d", localvar, count);
    count++;
    localvar++;
    return count;
}

int main() {
    // each time fun is called, the count is static so it remains 
    printf("the current count is %d\n", fun());
    printf("the current count is %d\n", fun());
    printf("the current count is %d\n", fun());
    printf("the current count is %d\n", fun());
    return 1;
}