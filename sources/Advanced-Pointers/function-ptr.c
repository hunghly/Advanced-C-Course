// functions contain addresses and thus, we can use pointers to point to functions
/**
 * pointers to functions can be:
 * passed to functions
 * returned from functions
 * stored in arrays
 * assigned to other function pointers
 * a function pointer can be used directly as the function name when calling the function
 * 
 * they are less error prone than normal pointers cause you will never allocate or deallocate memory with them
 * 
 * 
 * common use cases:
 * tells the function which function to use
 * sorting an array involves comparing two elements to see which comes first
 * create dispatch tables
 * menu-driven statements
 * replace switch/if statements
 * implement callbacks
 * 
 * syntax
 * a pointer to a function stores the address for the start of the function code
 * declaring a pointer to a function is going to be a little more complicated than declaring a pointer to a data type
 * 
 * declaration
 * must be declared, assigned values, then accessed
 * when you declare a function pointer, you must declare the type of the function pointered to
 * to specify the function type, you must specify the signature(the return type, the parameter types for a function)
 * int (*pfunction)(int);
 *  -declares a variable that is a pointer to a function
 *  -name of pointer is pfunction
 *  -we need the ()'s because of order of precedence
 * 
 * it's common to use typedef with complex types like function pointers
 */
#include <stdio.h>


int printint(int);
int (*pfunction)(int) = printint;
typedef int (*funptr)(); // funptr is now a synonym for the type of a pointer to a function that takes no
// arguments and returns an int

int main(void) {

    printint(10);
    (*pfunction)(100); // call the function like this
    pfunction(230); // or call like this

    funptr testvar;
    

    return 0;
}

int printint(int num) {
    printf("Your int is: %d\n", num);
    return num;
}
