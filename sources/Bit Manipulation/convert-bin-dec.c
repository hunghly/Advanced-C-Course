#include <stdio.h>
#include <string.h>
#include <math.h>

long long convertDecToBin(int n);
int convertBintoDec(long long n);

int main(void) {
    // convert binary to dec then dec to binary
    printf("Your decimal number is %d\n", convertBintoDec(100001010));
    printf("Your binary number is %lld\n", convertDecToBin(10));

    
}

int convertBintoDec(long long n) {
    int decimalNumber = 0, i = 0, remainder = 0;
    while (n != 0) {
        remainder = n % 10; // get us the last digit
        n = n / 10; // get the next number
        decimalNumber += remainder * pow(2,i);
        ++i;
    }
    return decimalNumber;
}

long long convertDecToBin(int n) {

    long long binaryNumber = 0;
    int remainder, i=1;
    while (n != 0) {
        remainder = n % 2;
        n = n / 2;
        binaryNumber += remainder * i;
        i = i * 10;
    }
    return binaryNumber;
}