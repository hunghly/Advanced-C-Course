#include <stdio.h>

// define a union named student that consists of three elements
// 1. char letterGrade
// 2. int roundedGrade
// 3. float exactGrade

// should declare two union variables inside the main method (var 1 and 2)
// assign random values to var 1 and print out everything
// assign values to each element of var 2 and print out each after assign

union Student {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

int main(void) {
    union Student student1, student2;
    union Student *ptrStudent = &student2;

    // Incorrect
    student1.letterGrade = 'A';
    student1.roundedGrade = 99;
    student1.exactGrade = 98.8;
    printf("LG %c\n", student1.letterGrade);
    printf("RG %d\n", student1.roundedGrade);
    printf("EG %f\n", student1.exactGrade);

    // Correct
    ptrStudent->letterGrade = 'B';
    printf("LG %c\n", ptrStudent->letterGrade);
    ptrStudent->roundedGrade = 88;
    printf("RG %d\n", ptrStudent->roundedGrade);
    ptrStudent->exactGrade = 87.5;
    printf("EG %f\n", ptrStudent->exactGrade);


}