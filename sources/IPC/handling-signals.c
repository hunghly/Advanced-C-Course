#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler_dividebyzero(int signum);

int main(void) {

    // signal can be done via signal() or sigaction()
    // void (*signal( int sig, void (*handler) (int))) (int);
    // it takes two functions, the signal and the handler
    int result = 0;
    int v1 = 0, v2=0;
    void (*sigHandlerReturn)(int);
    sigHandlerReturn = signal(SIGABRT, handler_dividebyzero); // registers signal handler
    if (sigHandlerReturn == SIG_ERR) {
        perror("Signal Error: ");
        return -1;
    }
    v1 = 121;
    v2 = 0;
    result = v1/v2;
    printf("V1 / V2 = %d\n", result);

    return 0;
}

void handler_dividebyzero(int signum) {
    if (signum == SIGFPE) {
        printf("Received SIGFPE, Divide by Zero Exception\n");
        exit(0);
    }
    else if (signum == SIGABRT) {
        printf("Aborting\n");
        exit(0);
    }
    else {
        printf("Received %d Signal\n", signum);
        return;
    }
}