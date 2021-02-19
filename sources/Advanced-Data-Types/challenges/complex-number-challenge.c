#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {
    // write a program that performs some calculations on complex numbers
    // create a double complex number with the imaginary number squared using multiplcation operator (I * I)
    // display as output the real number and the imaginary number

    //create a double complex number with the imaginary number squared using the pow function from the math library
    // i.e. pow(I,2)
    // dis as output the real number and the imaginary number

    //create a double complex number that performs Euler's formula
    // PI = acos(-1)
    // the complex number is the exponent of I * PI
    // display as output the real number and imaginary number

    // create a double complex number that performs a conjugate
    // a number that is 1+2i
    // a number that is 1-2i

    #ifdef _STDC_NO_COMPLEX_
        printf("Complex arithmetic is not supported\n");
    #else
        printf("Complex arithmetic iss supported\n");
        double complex c1 = I * I;
        // double complex c1sq = c1 * c1;
        double complex c1pow = pow(I, 2);
        printf("c1 is %.2f%+.2fi\n", creal(c1), cimag(c1));
        // printf("c1 squared is %.2f%+.2fi\n", creal(c1sq), cimag(c1sq));
        printf("c1 squared w/ pow is %.2f%+.2fi\n", creal(c1pow), cimag(c1pow));

        double complex euler;
        double PI = acos(-1);
        printf("PI is %ld\n", PI);
    #endif
}