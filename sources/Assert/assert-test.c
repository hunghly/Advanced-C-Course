/*
assert is designed to help with debugging programs
the assert macro enables you to insert tests of arbitrary expressions in your program
takes an argument an integer expression
the program will terminate with diagnostic message if the exprewsion is false during execution

*/
#define NDEBUG // this will switch off runtime asserts
#undef NDEBUG // turns back on runtime asserts
#include <stdio.h>
#include <assert.h>

// for compile time assertions you can use static_assert
// static_assert(constant_expressions, string_literal);



int main(void) {
    int x = 1;
    int y = 5;
    static_assert(x > y, "x must be greater than y for this to work"); // this will stop the code from working during compile time and alert the user
    assert( x > y ); // will print out an error if condition fails
    return 0;
}
