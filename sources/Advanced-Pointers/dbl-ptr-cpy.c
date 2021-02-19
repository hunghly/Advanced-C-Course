// the biggest reason to use a double pointer is when you need to change the value of the pointer
// passed to a function as the function argument
// **simulate pass by reference
// basically when you create a function, it creates a copy of the pointer - it does not
// use the pointer's reference so if you changed the value, it wouldn't affect the original pointer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void changemyname(char* name);
void changemynamebydblptr(char**name);

int main(void) {
    /* If you pass a single pointer as an argument, you will be modifying 
    local copies of the pointer, not the origin pointer to the calling 
    scope. with a pointer to a pointer, you modify the original pointer
    */

    char *myname = "Hung";
    char **dblptr = &myname;

    printf("myname is: %s\n", myname);
    changemyname(myname);
    printf("myname is: %s\n", myname); // did not change the name since it passed a copy

    changemynamebydblptr(dblptr);
    printf("myname changed is: %s\n", myname); // did change the name because the pointer to the address of myname was passed in

    return 0;
}

void changemyname(char* name) {
    char *newname = "Joe";
    printf("name inside function before change: %s\n", name);
    name = newname;
    printf("name inside function after change: %s\n", name);
}

void changemynamebydblptr(char**name) {
    char *newname = "John";
    printf("name inside function before change: %s\n", *name);
    *name = newname;
    printf("name inside function before change: %s\n", *name);
}