#include <stdio.h>

// the volatime type qualifier tells the compiler explicitly that the specified variable will change its value
// it is provided so that a program can tell the compiler to suppress various kinds of optimizations
// prevents the compiler from optimizing away seemingly redundant assignments to a variable
// prevents the compiler from repeated examination of a variable without its value seemingly changing
// essentially prevents the compiler from 'caching variables'
// the reason for having this type of qualifier is mainly because of the problems that are encountered in real-time or embedded systems programming such as a lot of threading or where resources are scarce

int main(void) {

    // a variable should be declared volatile whenever its value could change unexpectedly
    // the optimizer much be careful to reload the vvariable every time it is used isntead of holding a copy in a register
    // only 3 types of variables should use volatile
    // 1. memory-mapped peripheral registers
    // 2. global variables (non stack variables) modified by an interrupt service routine
    // 3. global variables accessed by multiple tasks within a multi-threaded application

    volatile int loc1; // loc1 is a volatile location
    volatile int *ploc; // ploc points to a volatile location

    int x;
    int val1 = x;

    // some random code that doesn't modify x

    int val2 = x; // the optimizer might cache x into a register because it thinks that the value x does not change


    // ========another example=========
    int *outPort;
    *outPort = 'O';
    *outPort = 'N';
    // the optimizer might remove the first assignment since it thinks that it will be override
    // instead use volatile int *outPort; to prevent this

    // a volatile can be used with a const

}