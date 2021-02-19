#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // create a single normal int variable and assign a random value (non ptr)
    // create a single int pointer var
    // create a double int pointer var
    // assign the address of normal int var to single ptr var
    // assign the address of single ptr var to double ptr var
    int x = 88;
    int *sptr = (int*) malloc(sizeof(int));
    int **dptr = (int**) malloc(sizeof(int));
    sptr = &x;
    dptr = &sptr;
    printf("Your variable is: %d\n", x);
    printf("Your variable using sptr is: %d\n", *sptr);
    printf("Your variable using dptr is: %d\n", **dptr);

    printf("Your variable addr is: %p\n", &x);
    printf("Your variable addr using sptr is: %p\n", sptr);
    printf("Your variable addr using dptr is: %p\n", *dptr);

    printf("Your value of sptr is: %p\n", sptr);
    printf("Your value of dptr is: %p\n", *dptr);

    free(sptr);
    free(dptr);
    return 0;
}