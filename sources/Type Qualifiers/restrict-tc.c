#include <stdio.h>
#include <stdlib.h>


/**
 * @brief 
 * 
 * the restrict type qualifier is an optimization hint for the compiler (the compiler can choose to ignore it)
 * -it is used in pointer declarations as a type qualifer for pointers
 * -tells the compiler that a particular pointer is the only reference to the value it points to throughout it's scope
 *  -the same value is not referenced by any other pointer or variable in that scope
 *  -the pointer is the sole initial means of accessing a data object
 * -tells the compiler it does not need to add any additional checks
 * 
 * without the restrict keyword, the compiler has to assume the worst case
 * with the restrict keyword, the compiler is free to look for computational shortcuts
 * 
 * SYNTAX
 * int *restrict intPtrA;
 * int *restrict intPtrB;
 * -tells the compiler that for the duration of the scope in which intPtrA
 * and intPtrB are defined, they will never access the same value
 * -their use for pointing to ints inside of an array is mutually exclusive
 */

void f1(int n, float *restrict a1, const float *restrict a2) {
    int i;
    for (i = 0; i < n; i++) { // each iteration of the loop is independent of the others
        a1[i] += a2[i];
    }
}

int main(void) {
    
    int n;
    int array[10];
    int *restrict restar = (int*) malloc(10*sizeof(int));
    int *par = array;

    for (n = 0; n < 10; n++) {
        par[n] += 5;
        restar[n] += 5;
        array[n] *= 2;
        par[n] += 3;
        restar[n] += 3;
    }
    
}