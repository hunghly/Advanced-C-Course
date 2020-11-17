#include <stdio.h>
#include <complex.h>

int main(void)
{
// a complex number is a number of the form a + bi
// i is the square root of minus one (imaginary number)
// a & b are real numbers
// a is called the real part and bi is the imaginary part of the complex number
// a complex number can also be regarded as an ordered pair of real numbers(a,b)
// you can perform modulus, equality, and addition to complex numbers

// C99 introduces support for complex numbers and C11 is not obligated to implement complex arithmetic
// you can test to see if the compiler supports complex arithmetic using preprocessor directives
    #ifdef _STDC_NO_COMPLEX_
        printf("Complex arithmetic is not supported\n");
    #else
        printf("Complex arithmetic is supported\n");
        double complex cx = 1.0 + 3.0 * I;
        double complex cy = 1.0 - 4.0 * I;

        printf("Working with complex numbers:\n");
        printf("Starting values for cx = %.2f%+.2fi cy = %.2f%+.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));

        double complex sum = cx + cy;
        printf("\nThe sum cx + cy = %.2f%+.2fi\n", creal(sum),cimag(sum));


    #endif

    //float _Complex a;// stores a complex number with real and imaginary parts as type float
    //double _Complex b; // same but as type double
    //long double _Complex c;
    //float _Imaginary d; //stores an imaginary number float
    //double _Imaginary e; // stores an imginary number as double
    //float imaginary num1 = 3*I;
    //float imaginary num2 = 4*I;

    // double real_part = creal(z1) // gets the real part of z1
    // double imag_part = cimag(z1) // gets the imaginary part of z1

    // conj() - returns the complex conjugate of it's double complex argument
    

}