#include <stdio.h>

// does not contain all three data types, just one at a time
union Data {
    int i;
    float f;
    char str[20];
} data; // currently the Data union occupies 20 bytes which is the largest field (char str[20])

// structures can be defined that contain unions as can arrays
// pointers to unions can also be declared, their syntax and rules for performing operations are the same as for structures

union Car {
    int i_value;
    float f_value;
};

#define entries 10

enum symbolType {
    type1, type2
};

struct {
    char *name;
    enum symbolType type;
    union {
        int i;
        float f;
        char c;
    } data;
} tables[entries];

int main(void) {
    union Car car1, car2, *car3; // declare three different types of cars;
    union Car car4 = {10}; // initializes the first member of the union
    union Car car5 = {.f_value = 12}; // initializes the f_value when declaring the union

    printf("Memory size occupied by Car %zu\n", sizeof(car1));

    // You can use the dot operator to access members of a union and -> to access pointer variables (indirection operator)
    car1.i_value = 10;
    printf("car1 i val: %d\n", car1.i_value);
    car2.f_value = 12.1;
    printf("car2 i val: %f\n", car2.f_value);
    car3 = &car1;
    car3->i_value = 10;
    printf("car3 i val: %d\n", car3->i_value);

    return 0;
}