#include <stdio.h>

int somedisplay();
void func1(int);
void funct2(int);
char* printHello(void);

typedef int FuncType(int);
typedef char CharType(void);

int main() {

    // int (*func_ptr)();

    // func_ptr = somedisplay;

    // printf("Address of func_ptr %p\n", func_ptr);

    // func_ptr();
    // (*func_ptr)();

    FuncType *func_ptr1 = NULL;
    func_ptr1 = somedisplay;
    
    func_ptr1(1);

    CharType *charptr = NULL;
    charptr = printHello;

    charptr();

    return 0;
}

int somedisplay(int testarg) {
    printf("\nHello World! %d\n", testarg);
    return 0;
}

char* printHello() {
    printf("Hello");
    return "Hello";
}