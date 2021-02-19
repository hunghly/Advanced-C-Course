#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // a pointer has an address, a value for that address, and the dereference
    // We already know that a pointer points to a location in memory and thus used to store the address of variables. So, when we define a pointer to pointer. The first pointer is used to store the address of the variable. And the second pointer is used to store the address of the first pointer. That is why they are also known as double pointers
    
    // pointer (holds address) => variable(holds value)
    // double pointer (holds address of pointer) => pointer(holds address) => variable(holds value)
    int *intptr;
    int x = 10;
    intptr = &x;
    printf("intptr address: %d\n", *intptr);

    int **ipp;

    int i = 5;
    int j = 6, k =7;
    int *ip1 = &i;
    int *ip2 = &j;

    // assign double pointer to ip1's address
    ipp = &ip1;

    // therefore, *ipp is ip1, **ipp is i
    printf("ipp is %d\n", **ipp);

    int *someint = malloc(sizeof(int));
    *someint = 10;
    printf("someint is %d\n", *someint);

    // lets change *ipp = ip2; well *ipp is actually ip1 so it's the same was ip1 = ip2
    

    return 0;
}