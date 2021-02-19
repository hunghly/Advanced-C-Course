#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int *ptr) {
    // this will be a copy
    int a = 5;
    ptr = &a; // this is going to be local address
}
void dblfoo(int **ptr) {
    // this will pass by reference
    int a = 5;
    ptr = malloc(sizeof(int));
    *ptr = &a; // dereference the ptr so it's the value and assign it the address of a
    printf("a is %d\n", **ptr);
    free(ptr);
}

void wordfoo(char **ptr) {
    *ptr = malloc(255);
    strcpy(*ptr, "Hello World");
    // free(ptr);
}

int main(void) {
    int *ptr = NULL;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 10;
    printf("ptr %d\n", *ptr);

    // foo(ptr);
    dblfoo(&ptr);
    char *buf = malloc(50* sizeof(int));
    printf("ptr %d\n", *ptr);

    sprintf(buf, "This is my int: %d", *ptr);
    puts(buf);
    char *ptr2 = NULL;
    wordfoo(&ptr2);
    printf("ptr2 %s\n", ptr2);

    free(buf);
    free(ptr);
    return 0;
}