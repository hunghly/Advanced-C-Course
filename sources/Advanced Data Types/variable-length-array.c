#include <stdio.h>

// you can error check to make sure the compiler supports variable length arrays
#ifdef _STDC_NO_VLA_
    printf("Variable length arrays are not supported.\n");
    exit(1);
#endif

int sum2d(int rows, int cols, int array[rows][cols]); // must declare int array[rows][cols] after \
int rows and int cols because the compiler needs to know the value

// in C99 or C11 you can omit the names and use
int sum2d_2(int, int, int array[*][*]);

void array(int size) {
    int array[size];

    int x = 0;

    while (x < size) {
        array[x] = 'A' + x;
        printf("array is: %c: \n", array[x]);
        x++;
    }
}

int main(void) {
    size_t size = 0; //size_t is the unsigned integer type of the result of sizeof ,\
     _Alignof (since C11) and offsetof, depending on the data model.

    // printf("Enter the number of elements you want to store: ");
    // scanf("%zd", &size);

    // float values[size];

    array(40);

    int arr1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printf("Total is %d\n", sum2d(3,3, arr1));

    return 0;
}

int sum2d(int rows, int cols, int array[rows][cols]) {
    int r;
    int c;
    int total = 0;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            total += array[r][c];
        }
    }
    return total;
}