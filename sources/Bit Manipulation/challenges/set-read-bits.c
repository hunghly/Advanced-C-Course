#include <stdio.h>

int main(void) {
    // write a program to input any number from the user
    // should check whether nth bit of a given number is set (1) or not
    // should also set nth bit of given number as 1
    // i.e.
    // enter 10, check nth bit 2, the 2 bit is set to 0, set 2 bit to 1, output new bit

    int num;
    int num_s;
    int nbit;
    int nbit_v;
    int count = 32;
    printf("Please enter any number:");
    scanf("%d", &num);
    printf("Please enter nth bit to check and set (0-31):");
    scanf("%d", &nbit);

    nbit_v = (num >> nbit) & 1;
    printf("The %d bit is set to %d\n", nbit, nbit_v);

    // Set the bit
    num = num | 1 << nbit;
    printf("Your new number is: %d\n", num);

    //prints out the bits
    while (count >= 0) {
        printf("%d", (num >> count) & 1);
        count--;
    }
    printf("\n");
}