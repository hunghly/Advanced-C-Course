#include <stdio.h>

int main() {
    short int w1 = 25;
    short int w2 = 77;
    short int w3 = 0;
    short int w4 = 0;
    short int w5 = 0;
    short int w6 = 0;
    short int w7 = 0;

    w3 = w1 & w2;
    // w3 & operation
    // 0000 0000 0001 1001 (25)
    // 0000 0000 0100 1101 (77)
    // ========================
    // 0000 0000 0000 1001 (9)
    // you only set it to 1 if both have 1 inside of it (true only if both are true)
    printf("w3 is %d\n", w3);

    w1 = 147, w2= 61;
    w4 = w1 | w2;

    // 0000 0000 1001 0011 (147)
    // 0000 0000 0011 1101 (61)
    // =========================
    // 0000 0000 1011 1111 (191)
    // you set it to 1 if either has 1
    printf("w4 is %d\n", w4);

    w5 = w1 ^ w2;
    // 0000 0000 1001 0011 (147)
    // 0000 0000 0011 1101 (61)
    // =========================
    // 0000 0000 1010 1110 (174)
    // you set it to 1 if only one has a 1
    printf("w5 is %d\n", w5);

    w6 = w6^w1; // since w6 is 0, it copies the values of w1 into it
    printf("w6 is %d\n", w6);

    w1 = 2;
    signed int result = 0;

    // 0000 0000 0000 0010 (2)
    // 1111 1111 1111 1101 (-3) flips the bits and gives the one's complement
    result = ~w1;
    printf("result is is %d\n", result);


    // 1001 1010 (154)
    // =========
    // 0110 0101 
    // 0000 0001 // add 1
    // 0110 0110 // twos complement of 154 or -154

    // useful when you do not know the precise bit size of the quantity that you are dealing with in an operation
    // can make the program more portable

    // to set the low-order bit of an int called w1 to 0, you can AND w1 with an int consisting \
    of all 1s except for a single 0 in the rightmost bit
    // i.e. w1 &=0xFFFFFFFE; works on machines in which an integer is represented by 32 bits
    // w1 &=~1; is the same as the above

    return 0;
}