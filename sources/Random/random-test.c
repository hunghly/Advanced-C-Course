#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

    // srand seeds the pseudo random number generater used by rand. If rand() is called before any calls to srand(), rand()
    // behaves as if it was seeded with srand(1) and each time rand() is seeded with srand(), it must produce the same sequence of values
    // it should not be repeatedly seed and not reseeded every time you wish to generate a new batch of pseudo random numbers
    // standard practice is to use the result of a call to srand(time(0)) as the seed
    // time() returns a time_t value which varies every time and hence the pseudo-random number varies for every call
    
    srand(time(0)); // seeds the random function

    // rand returns  pseudo-random int value between 0 and RAND_MAX
    int x;
    printf("random num using time: %ld\n", time(0));
    for (int i = 0; i < 5; i++) {
        x = rand();
        printf("random # is %d\n", x);
        printf("if you want only random values you can mod it: %d\n", x % 5 + 1);
    }

    

    return 0;
}