#include <stdio.h>
#include <string.h>

int sum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int gcd(int n1, int n2) {
    if (n2 == 0) { // base case
        return n1;
    } else {
        return gcd(n2, n1 % n2);
    }
}

char* reverse(char *str) {

    static int i = 0;
    static char rev[100];

    if (*str) {
        reverse(str + 1);
        rev[i++] = *str;
        puts(rev);
    }
    return rev;
}

int main(void) {
    // write a porgram that sums the numbers from 1 to n using recursion
    // printf("The sum of numbers from 1 to %d is %d\n", 10, sum(10));



    // write a program that will find the GCD of two numbers using recursion
    // input 10, 50 the GCD is 10
    // printf("The gcd of 10 and 50 is %d\n", gcd(10,50));

    // write a program that will find the reverse of a string using recursion
    // studytonight -> thginotyduts
    char *str1 = "studytonight";
    
    printf("Reverse of %s is %s\n", str1, reverse(str1));




    return 0;
}