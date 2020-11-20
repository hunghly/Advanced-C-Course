// you can pack information into bits of a byte if you do not need to use the entire byte to represent the data
// the flags that are used for a boolean true or false condition can be represented in a single bit on a computer
// two methods are available in C that can be used to pack information together to make better use of memory
// -bit fields and bitwise operators
// two ways to pack information together to make better use of memory
// 1. use an unsigned int/long variable to hold the same information
// 2. use a structure the same size as unsigned int to hold state information

// =======PACK INFO INTO AN INT OR LONG VARIABLE=========
// flags that are used for a boolean true or false condition can be represented in a single bit on a computer
// each bit in the int can be set to 1 (true) or 0 (false)
// we access the desired bits of the int using the bit operators provided by C
// EXAMPLE
/**
 * you want to pack five data values into a word because you have to maintain a large table of values in memory
 * -assume that three of these values are flags f1, f2, f3
 * -the fourth value is an integer called type which ranges from 1 to 255
 * -the final value is an integer called index which ranges from 0 to 100,000
 * 
 * storing the values of f1, f2, f3 only require three bits of storage
 * storing the value of the int type requires 8 bits of storage
 * storing the value of interger index requires 18 bits
 * the total amount of storage needed to store five data values is 29 bits
 * 
 *f1,f2,f3      type        index
 * 000          0000 0000   0 0000 0000 0000 0000
 * unsigned int packed_data; // usually 32 bits on most systems
 * -you would use a bitmask or bitwise operator to set and retrieve values
 * */

#include <stdio.h>

long long convertDecimalToBinary(long n);

int main(void) {
    long packed_data= 0;

    packed_data |= 7 << 18;
    printf("%ld or in binary %lld\n", packed_data, convertDecimalToBinary(packed_data));

    // to set the type field to the value n where n is 0 -255, you can ensure it's between that value by AND it with 0xff before it is shifted
    //packed_data |= n << 18;
    // to zero out the type field, you would need to AND it with a bit mask that consists of all 0's in the eight bit locations where type is and 1's everywhere else
    // in this case it's 0xFC03FFFF;
    // -BUT in order to avoid doing a bunch of calculations you can use pack_data &= ~(0xFF << 18)
    // which shift the data to the left 18 (index) and sets 8 bits to 1, and then inverts them to 0's


    // to read a bit you can use AND and shift
    long n;
    n = (packed_data >> 18) & 0xff;

    printf("n is: %ld or %lld\n", n, convertDecimalToBinary(n));

}

long long convertDecimalToBinary(long n)
{
    long long binaryNumber = 0;
    long long remainder, i = 1;
    while (n != 0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber = binaryNumber + (remainder*i);
        printf("bn:%lld, n:%ld, remainder:%ld, i:%ld\n", binaryNumber, n, remainder, i);
        i *= 10;
    }
    return binaryNumber;
}