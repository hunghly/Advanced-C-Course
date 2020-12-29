#include <stdio.h>

// a macro is piece of code based on the #define directive
// macros are a text processing feature that will be "expanded" and replaced by by macro definitions
// today macros in C are considered out of date in terms of programing practices but they are still widely used since it makes it easier for the programmer
// syntax: #define MACRO macro_body
// i.e. #define PX printf("x is %d\n", x)
// macros run until the first newline following the # unless using the \ contination symbol
// 

#define PRNT(a,b) /* must use \ to continue to next line without breaking */\
    printf("Var 1 is %d\n", a); \
    printf("Var 2 is %d\n", b);

int main(void) {
    int x = 10;
    int y = 15;
    PRNT(x,y);

    // what happens is that PRNT(x,y) is replaced by:
    // printf("Var 1 is %d\n", x);
    // printf("Var 2 is %d\n", y);

    return 0;
}