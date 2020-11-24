#include <stdio.h>

// you can use bit fields in a structure to address individual bits or groups of bits in a value
// a bit field allows you to specify the number of bits in which an int member of a structure is stored
// uses a special syntax in the structure definition that allows you to define a field of bits and assign a name\
 to that field
// should use the explicit declarations signed int or unsigned int to avoid problems with hardware dependencies
// C99 and C11 allow type_Bool bit fields

// a bit field is declared by following an unsigned int member name with a colon (:)
// an integer constant is placed after the colon which represents the width of the field
    // -the number of bits in which the member is stored
    // - the constant representing the width must be an integer between 0 and thte total number of bits used to store\
    an int
// bit-field members of structures are accessed exactly as any other structure member
// it is possible to specify an unnamed bit field to be used as padding in the structure
// - an unnamed bit field with a zero width is used to align the next bit field on a new storage unit boundary

struct packed_struct {
    int count;
    char c;
    unsigned int :3; // padding by 3 or 3 unused bits
    unsigned int f1:1; // flag 1
    unsigned int f2:1; // flag 2
    unsigned int f3:1; // flag 3
    unsigned int type:8;
    unsigned int index:18;
    // this declares the same 32-bit bitmask that we used earlier for the challenge

};


int main(void) {
    struct packed_struct packed_data = {0, 0, 0, 0, 0, 0, 0};
    packed_data.type = 7;
    unsigned int bit = packed_data.type; // this sets the bitmask for type to 7 to bit. it does the
                                            // shifting and assignment for us

    // unsigned int i = packed_data.index / 5 + 1;
    printf("unsigned bit is : %d\n", bit);
    printf("unsigned index is : %d\n", packed_data.index);



    return 0;
}