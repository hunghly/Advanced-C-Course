#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signalHandler(int signalValue);

int main(void) {
    int i;
    int x;
    signal(SIGINT, signalHandler); // register signal handler
    // signal(SIGINT, SIG_IGN); // executes signal ignore when SIGINT is received
    srand(clock()); // generates a random seed based on clock

    for (i = 1; i <= 100; i++) {
        x = 1 + rand() % 50; // generate random number to raise SIGINT
        printf("x is %d\n", x);
        if (x == 25) {
            raise(SIGINT); // no matter what signal gets generated, it get handled by the signal handler
        }
    }


    return 0;
}

void signalHandler(int signalValue) {
    int response;
    printf("%s%d%s\n%s", "\nInterrupt signal ( ", signalValue, " ) received", "Do you wish to continue 1=yes, 2 = no");
    scanf("%d", &response);

    // check for invalid responses
    while (response != 1 && response != 2) {
        printf("1 = yes or 2 = no?");
        scanf("%d", &response);
    }

    if (response == 1) {
        signal(SIGINT, signalHandler);
    } else {
        exit(EXIT_SUCCESS);
    }
}