#include <stdio.h>

int main(void) {
    // for (; (c=getchar() != EOF; putchar(c))) // this is an example of a null statement

    // example 2, finding the index of first occurence of a certain char in a string
    int a[50] = "the empire strikes back";
    int i;

    for (i=0; a[i] != 't'; i++)
    ; // null statement
    // no operation is required and i is set to location of first 't'
}