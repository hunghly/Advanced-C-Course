#include <stdio.h>
#include <stdlib.h>

struct myArray {
    int length;
    int array[];
};

int main(void) {
    // write a program that uses a flexible array member inside a structure
    // create a structure named myArray that has a length member and a flexible array member named array
    // read in from the user the size of the array at runtime
    // allocate memory for the structure based on this size read from the user
    // set the length member and fill the array with some dummy data
    // print array elements

    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    struct myArray *myArr;
    myArr = malloc(sizeof (struct myArray) + length * sizeof(int));
    myArr->length = length;
    printf("the length of the struct myArray is: %d\n", myArr->length);
    for (int i = 0; i < myArr->length; i++) {
        printf("Enter a number for the array: ");
        scanf("%d", (myArr->array + i));
    }
    for (int i = 0; i < myArr->length; i++) {
        printf("%d\n", *(myArr->array + i));
    }
}

