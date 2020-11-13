#include "other.h"

int globalVar = 35; // declare a global variable
static int notOutsideVar = 30; // this is a global variable that is not accessible by extern keyword or to other files

int getfavoritenumber(void) {
    return 3;
}