#include <stdio.h>

//#define is a pre-processor directive and const is a keyword
/**
 * const variables are actual variables like any other normal variable - we can pass them, typecast, etc.
 * #define is not scope controlled whereas const is scope controlled
 * const provides for type checking by the compiler
 *  
 */

int main(void) {
    typedef const int zip; // declare an alias for a const int called zip

    zip q = 8;

    // apply const to a pointer
    const float *pf; // pf points to a constant float value
    float *const pt; // the pt is a const pointer i.e. the address can't change
    const float *const ptr; // the ptr value and address is const

    float const *pfc; // the same as const float *pfc;

    int const k = 5; // can declare const after the type

    return 0;

}