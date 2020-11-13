#include <stdio.h>
#include "other.h"
#include "random.h"

extern int globalVar; // access a global variable using extern keyword (from other.c)

int main(void) {

    printf("My favorite number is: %d\n", getfavoritenumber());
    printf("Printing global var %d\n", globalVar);


}