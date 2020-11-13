#include <stdio.h>
#include <stdlib.h>
/* //This is how memory is managed on the stack
double multiplyByTwo(double input) {
    double twice = input * 2.0;
    return twice;
}

int main() {
    // all of these variables are pushed to the stack and removed after function exit
    int age = 30;
    double salary = 12345.67;
    double myList[3] = {1.2, 2.3, 3.4};

    printf("double your dalary is %.3f\n", multiplyByTwo(salary));
}
*/

// This is how memory is stored on heap
double *multiplyByTWo(double *input) {
    double *twice = malloc(sizeof(double));
    *twice = *input * 2.0;
    return twice;
}

int main(int argc, char* argv[]) {
    int *age = malloc(sizeof(int));
    *age = 30;
    double *salary = malloc(sizeof(double));
    *salary = 12345.67;
    double *myList = malloc(3 * sizeof(double));
    myList[0] = 1.2;
    myList[1] = 2.3;
    myList[2] = 3.4;
    double *twiceSalary = multiplyByTWo(salary);

    printf("double your dalary is %.3f\n", *twiceSalary);
    free(age);
    free(salary);
    free(myList);
    free(twiceSalary);
}