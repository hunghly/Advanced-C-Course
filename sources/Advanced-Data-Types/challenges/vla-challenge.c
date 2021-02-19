#include <stdio.h>

typedef int my_int;

int sumArray(int size, int array[size]) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int main(void) {
    // write a program to read elements in an array and find the sum of array elements
    my_int elems;
    my_int counter = 0;
    printf("How many elements do you want to enter?\n");
    scanf("%d", &elems);
    my_int arr[elems];
    printf("You entered %d elements. Please enter them now.\n", elems);
    while (counter < elems) {
        scanf("%d", &arr[counter]);
        printf("Stored\n");
        counter++;
    }

    printf("Your sum is: %d\n", sumArray(elems, arr));

}