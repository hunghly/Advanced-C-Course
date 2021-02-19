// using noreturn macro
#include <stdnoreturn.h>
#include <stdio.h>
#include <stdlib.h>


_Noreturn void f() {
    // abort(); // ok
}

_Noreturn void g(int i) {
    // causes undefined behavior if i <= 0
    if (i > 0) {
        // abort();
    }
}



noreturn void my_exit(void);

void my_exit(void) {
    printf("Exiting...\n");
    exit(0); // must exit the program otherwise itw ill be undefined behavior since it should not return
}

int main() {
    // C11 added another function specifier called _Noreturn
    // the purpose is to inform the user and the compiler that a particular function will not return control to the calling program when it completes execution
    // informing the user helps prevent misuse of the function
    // could also make some code optimizations
    // just like inline specifier the _Noreturn is just a hint to the compiler and may not be used by the compiler
    // the exit() function is an example of a _Noreturn function - once exit is called, the function never resumes
    // THIS IS DIFFERENT THAN VOID RETURN TYPE - the void return type returns to the calling function with no assignable value
    // if a function specified with the _Noreturn specifier violates it's promise and eventually returns to it's caller, the behavior is UNDEFINED
    my_exit();
    return 0;
}