#include <stdio.h>
#include <signal.h>

int main(void) {

    // a sigaction is essentially a function wrapper
    // a struct that contains a pointer to a function
    // sigactions are used to tell the operating system which function it should call when a signal is sent to a process
    // the function is used to deal with or handle a signal that is sent to it
    // handlers are intended to be short, fast pieces of code and should do just enough to deal with the signal that has been received
    // the signal handling library <signal.h> provides the capability to catch and handle signals via sigaction
    // int sigactions(int signum, const struct sigaction *newaction, struct sigaction *oldaction);
    // parameter 1: the int value of the signal you want to handle
    // param: 2 - the address of the new sigaction you want to register
    // param 3: the old action if you pass a pointer to another sigaction, it will be filled with the details of the current handler that you are about to replace
    
}