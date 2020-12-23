#include <stdio.h>
#include <stdlib.h>


int factorial(int n) {
    if (n == 0) { // when called with base case, it returns the result
        return 1;
    }
    return (n * factorial(n-1)); // when the function is called with a more complex problem, it dives the problem into two conceptual pieces \
                                    1. a piece that the function knows how to do\
                                    2. a slightly smaller version of the original problem\
                                    The sequence of smaller problems must converge into the base case
}

void up_and_down(int n) {
    printf("Level %d: n location %p\n", n, &n);
    if (n < 4) {
        up_and_down(n+1); // will call all levels up until level 4 and then goes back down since it continues the execution
    }
    printf("LEVEL %d: n location %p\n", n, &n);
}

int main(void) {
    // the programs we have discussed are generally structured as functions that call one another in a hierarchical manner
    // for some types of problems it is useful to have functions call themselves
    // a recursive function is a function that calls itself directly or indirectly
    // can be effectively used to succinctly and efficiently solve problems
    // commonly used in applications in which the solution to a problem can be expressed in terms of successively applying the same solution to subsets of the problem
    // unlikely to come across a need for recursion very often

    // when the function calls itself, theres a problem with how it stops itself
    // it must contain a basecase that terminates the function

    // any problem that can be solved recursively can also be solved iteratively
    // both iteration and recursion uses a control structure (iteration uses repetition structure and recursion uses selection structure)
    // iteration explicitly uses reptition structure and recursion achieves reptition through repeated function calls
    // both also have a termination case (base case for recursion and condition fail for iteration)
    // tail recursion is the simplest form of recursion which is when the call happens at the end of the function just before the return statement and acts like a loop
    // tail recursion saves a little bit on overhead since there's no need to save the stack frame



    // printf("The factorial of 5 is %d\n", factorial(5));
    up_and_down(1);
    return 0;
}