#include <stdio.h>

/**
 * macro vs function
 * macros are essentially functions but with different syntax 
 * macros are pre-processed so that means they are processed before the program compiles
 * 
 * macro
 * - macros are faster than functions since it does it inline and does not need to return call back to the program
 *  - if you intend to use the macro many times throughout the program it might make it faster than just a function multiple times
 *  - a macro inside of a nested loop is a good candidate for speed improvements
 * - when you use a macro, it creates an inline subsitution so if your macro has 1 line and you use it 20 times, you add 20 lines to
 * your program
 * - macros do not consider variable types
 * - do not deal with variable values but character strings
 * - it is hard to debug a macro, you can use gcc -E source_file.c to expand it
 * 
 * function
 * - when you call a function, it creates a new stack frame 
 * - considers the type of variables and will give error if types do not match
 * 
 * creating a macro-function
 * #define MACRO(variables) expression
 * a macro has it's arguments substituted when it is expanded 
*/

#define PI 3.14
#define SQUARE(X) ((X)*(X))
// #define CIRCLE_AREA(X) ((PI) * (X) * (X))
#define CIRCLE_AREA(X) (PI * X * X)

#define Warning(...) fprintf(stderr, __VA_ARGS__) // you can do a variadic argment using this format

#define MISC(x) (puts("Incrementing"), (x)++, printf("%d\n", x))
#define MAX(a,b) ((a) > (b)) ? (a) : (b)
#define UpTo(i, n) for ((i) = 0; (i) < (n); (i++))

int main(void) {
    // a function macro
    int squared = SQUARE(4+2);
    // if we don't put parenthesis around the variables in a macro the order of precendence causes errors
    // i.e. SQUARE(4+2) would evaluate to 4 + 2 * 4 + 2 => 4 + 8 + 2 = 14 which is wrong

    printf("Squared=%d\n", squared);
    int area = CIRCLE_AREA(5 + 2);
    printf("Area is %d\n", area);
    // incorrectly forgetting to put parenthesis around the macro variables would cause
    // CIRCLE_AREA(5+2) to be 3.14 * 5 + 2 * 5 + 2 => 3.14 * 5 + 10 + 2 => 15 + 10 + 2 = 27

    Warning("Warning message: %s. The second message %s\n", "Here's the message", "Another message");
    int x = 0;
    MISC(x);
    MISC(x);
    MISC(x);
    int y = 0;
    y = MAX(10, 11);
    printf("%d\n", y);
    int i;
    UpTo(i, 10);
    
}