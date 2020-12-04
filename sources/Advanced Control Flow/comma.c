#include <stdio.h>

int main(void) {
    // comma operator
    // lowest precedence of any C operator
    // acts as a sequence point

    // evaluates the first operand and discards the result then evaluates the second operand and returns\
     the value
    // can be used to separate multiple expressions anywhere that a valid c expression can be used
    int i;
    // while (i < 100) {
        //sum+= data[i], ++i;// does both the sum assignment and increment

        //int i(5,10); // 10 is assigned to i
        // int j = (f1(), f2());
        // x = (y = 3, (z = ++y) + 5);
        // return 1;
    // }
    int z;
    int y = (3, z = 12); // will discard 3 and return y = 12
    printf("y is %d, z is %d\n", y, z);
    int houseprice = 249, 500;
    printf("house price %d\n", houseprice);

    // for (i = 0, z = 100; i != 10; ++i, z-=10) {

    // }
}