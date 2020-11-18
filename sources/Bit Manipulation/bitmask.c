#include <stdio.h>

int main(void) {

    //=======TURNING BIT ON============
    int flags = 15;         // 0000 1111
    int mask = 182;         // 1011 0110

    flags = flags | mask;   // 1011 1111


    //=======TURNING BIT OFF============
    // lets say we want to turn off bit 1
    mask = 1;               // 0000 0001
    // then you can assign the flag using bitwise operator
                            // 1011 1111 - current flag
    flags = flags & ~mask;  // 1111 1110 - ~mask
                            //===========
                            // 1011 1110 - turned off bit 1

    printf("flags %d\n", flags);

    //======TOGGLING BIT================
    flags = 15;             // 0000 1111
    mask = 182;             // 1011 0110 - to do the toggling, you place the 1's in the mask where you want it to toggle
    flags = flags ^ mask;   // 1011 1001

    // how to check the value of bits?
    // you must first mask the other bits in flags so that you can compare only bit 1 of flags with mask
    if ((flags & mask) == mask) {}
    flags = 15;             // 0000 1111
    mask = 1;               // 0000 0001
    flags = flags & mask;   // 0000 0001
    printf("%d\n", flags);

}