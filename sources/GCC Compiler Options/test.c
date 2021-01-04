#include <stdio.h>

// gcc -Wall test.c -----used for compiling with warnings
// gcc -c test.c
// gcc -S test.c ----creates assembly code
// gcc -Wall test.c -o test -l m ----will link to the external math library
// gcc -g test.c ----provides debugging information
// gcc -v test.c ---verbose compile
// gcc -Wall -Werror test.c -----all warnings are treated as errors

/**
 * Optimization flags
 * without any optimization flags, the compiler's goal is to reduce the cost of compilation and make debugging produce the expected results
 * turning on optimization flags makes the compiler attempt to improve the performance and/or code size at the expense of compilation time and possibly the ability to debug
 * not all optimizations are controlled directly by a flag
 * most optimizations are completely disabled
 * you can invoke -Q --help=optimizers
 * 
 * 
 * 
 * GCC Environment Variables
 * GCC uses the following environment variables:
 * PATH - for searching the executables and runtime shared libraries(.dll, .so)
 * CPATH - for searching the include paths for headers, searched after paths specified in -l <dir> options
 * C_INCLUDE_PATH can be used to specify C headers if the particular language was indicated in pre-processing
 * LIBRARY_PATH for searching library paths for linking libraries and for searched after paths specified in -L <dir> options
 * 
 * "nm" is a commonly used tool to check if a particular function is defined in an object file
 *          -i.e. nm test.o
 * -a 'T' in the second columns indicate a function that is defined
 * -a 'U' indicates a function which is undefined and should be resolved by the linker
 * -"ldd" Utility (List Dynamic-Link Libraries) - examines an executable and displays a list of the shared libraries that it needs
 *      - i.e. lld a.out
*/

#include <math.h>


int main(void) {
    int i;
    float x = 1.5;
    puts("Hello World!");
    float squared = pow(x,2);
    printf("Squared is %f\n", squared);

    #ifdef MY_MACRO
        puts("Macro defined");
    #endif
    
}