/* #include <stdio.h>
#include <math.h>

int convertBintoDec(long long n);
long long convertDecToBin(int n);

int main(void) {

    // read two ints from user
    // print the result of applying
    // 1. the ~ operator for each number
    // 2. the &, |, and ^
    // 3. the << and >> operator
    // show results as binary strings

    int input;
    int input2;
    long long inputBin;
    long long input2Bin;

    printf("Please enter a value: ");
    scanf("%d", &input);
    printf("Please enter another value: ");
    scanf("%d", &input2);

    printf("You entered: %d which is %lld in binary and %d which is %lld in binary\n", \
     input, convertDecToBin(input), input2, convertDecToBin(input2));
    
    inputBin = convertDecToBin(input);
    input2Bin = convertDecToBin(input2);

    long long oneComp = ~inputBin;
    long long oneComp2 = ~input2Bin;
    printf("One's complement of %lld is %lld\n", convertDecToBin(input), oneComp);
    printf("One's complement of %lld is %lld\n", convertDecToBin(input2), oneComp2);

    // int andOp = 



    return 0;
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
} */

#include <stdio.h>

long long convertDecimalToBinary(int n);

int main()  {

    int num1 = 0, num2 = 0;
    long long b_num1 = 0, b_num2 = 0;

    int d_num1LeftShiftResult = 0;

    long long b_num1ComplementResult = 0;
    long long b_num2ComplementResult = 0;
    long long b_num1ANDnum2Result = 0;
    long long b_num1ORnum2Result = 0;
    long long b_num1ExORnum2Result = 0;
    long long b_num1LeftShiftResult = 0;

    /* Input number from user */
    printf("Enter an integer: ");
    scanf("%d", &num1);

    /* Input bit position you want to set */
    printf("Enter another integer: ");
    scanf("%d", &num2);

    b_num1 = convertDecimalToBinary(num1);
    b_num2 = convertDecimalToBinary(num2);

    d_num1LeftShiftResult = num1 << 2;

    b_num1ComplementResult = convertDecimalToBinary(~num1);
    b_num2ComplementResult = convertDecimalToBinary(~num2);
    b_num1ANDnum2Result = convertDecimalToBinary(num1 & num2);
    b_num1ORnum2Result = convertDecimalToBinary(num1 | num2);
    b_num1ExORnum2Result = convertDecimalToBinary(num1 ^ num2);
    b_num1LeftShiftResult = convertDecimalToBinary(num1 << 2);


    printf("The result of applying the ~ operator on number %d (%lld) is: %lld \n", num1, b_num1, b_num1ComplementResult);
    printf("The result of applying the ~ operator on number %d (%lld) is: %lld \n", num2, b_num2, b_num2ComplementResult);
    printf("The result of applying the & operator on number %d (%lld) and number %d (%lld) is: %lld \n", num1, b_num1, num2, b_num2, b_num1ANDnum2Result);
    printf("The result of applying the | operator on number %d (%lld) and number %d (%lld) is: %lld \n", num1, b_num1, num2, b_num2, b_num1ORnum2Result);
    printf("The result of applying the ^ operator on number %d (%lld) and number %d (%lld) is: %lld \n", num1, b_num1, num2, b_num2, b_num1ExORnum2Result);
    printf("The result of applying the left shift operator << on number %d (%lld) by 2 places is number %d (%lld)\n", num1, b_num1, d_num1LeftShiftResult, b_num1LeftShiftResult);

    return 0;
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1;
    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}


