#include <stdio.h>

int main(void) {
    // C has left and right shift (<< and >> operators)
    // for the left-shift operator, the vacated bits are set to 0
    // for the right-shift operator, the vacated bits are set to 0 if the value is unsigned

    // an int on most platforms is 32-bits (4 bytes)
    int i = 1; // 0000 0000 | 0000 0000 | 0000 0000 | 0000 0001
    int w1 = 3; // 0000 0000 | 0000 0000 | 0000 0000 | 0000 0011


    //=========================================================================================
    // LEFT SHIFTING
    int result = 0;
    result = w1 << 1; // shift the value by to the left 1 spot and assign to result
    // result is now 0000 0000 | 0000 0000 | 0000 0000 | 0000 0110 (6)
    printf("Result is: %d\n", result);

    w1 = 138; // 0000 0000 | 0000 0000 | 0000 0000 | 1000 1010 (138)
    result = w1 << 2; // shift to the value to the left 2 spots
    // result is now // 0000 0000 | 0000 0000 | 0000 0010 | 0010 1000 (552)
    printf("Result is: %d\n", result);

    //=========================================================================================
    // RIGHT SHIFTING
    unsigned int w2 = 3; // 0000 0000 | 0000 0000 | 0000 0000 | 0000 0011
    unsigned int result2 = w2 >> 1; // shift w2 to the right 1 bit
    // result2 is now // 0000 0000 | 0000 0000 | 0000 0000 | 0000 0001
    printf("Result2 is: %d\n", result2);

    // for signed int values you have to be careful because sometimes the right shift will use a '1' rather\
    than a '0' for values that are shifted over

    // you have to know the number of bytes when you shift

    //=========================================================================================


    return 0;
}