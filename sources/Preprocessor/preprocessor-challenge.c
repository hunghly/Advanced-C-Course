#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// write a macro that accepts two parameters and returns the sun
#define SUM(a, b) (a) + (b)
#define SQUARE(a) (a) * (a)
#define CUBE(a) (a) * (a) * (a)
#define IS_UPPER()                              \
    puts("Enter a character");                  \
    char x = getchar();                         \
    if (!isalpha(x))                            \
        printf("%c is not an alpha char\n", x); \
    else if (isupper(x))                        \
        printf("%c is upper\n", x);             \
    else if (islower(x))                        \
        printf("%c is lower\n", x);             \


int main(void)
{
    // write a program to print the values of the following predefined symbolic constants
    printf("FILE %s\n", __FILE__);
    printf("LINE %d\n", __LINE__);
    printf("func %s\n", __func__);
    printf("DATE %s\n", __DATE__);
    printf("TIME %s\n", __TIME__);
    printf("STDC %d\n", __STDC__);

    printf("Sum of %d + %d = %d\n", 5, 10, SUM(5, 10));
    printf("Square of %d = %d\n", 10, SQUARE(10));
    printf("Cube of %d = %d\n", 10, CUBE(10));
    IS_UPPER();

    return 0;
}