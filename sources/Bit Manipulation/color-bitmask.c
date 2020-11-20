#include <stdio.h>

#define BYTE_MASK 0xFF // the mask we will use to read/set bits
unsigned long color = 0x002a162f;
unsigned char blue,green,red;

int main(void) {

    red = color & BYTE_MASK;
    green = (color >> 8) & BYTE_MASK; // shift to right 8bits
    blue = (color >> 16) & BYTE_MASK; // shift to right 16bits

    printf("red: %d, green: %d, blue:%d\n", red, green, blue);

    return 0;
}