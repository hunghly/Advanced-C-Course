#include <stdio.h>

int i = 5;
char text[255];
int count = 10;

void foo();
extern void write_extern();

int main(void) {
    printf("my global var is %d\n", i);
    // foo(); // when you call foo, external var i is now 100 because it accessed that variable's value
    printf("my global var is %d\n", i); // now i is 100
    printf("end\n");
    write_extern();
}