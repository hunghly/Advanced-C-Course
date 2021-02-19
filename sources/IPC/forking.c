// in multi-tasking os, processes need a way to create new processes
// a new process is often needed to run other programs or to run a different "branch"

// the fork() system call is a function where a process creates a copy of itself
// -creates a new process. defined in <unistd.h>

// when forked, the parent process creates a child process and they do not share memory space, variables, etc.


// often used with exec() system call to start the execution of a different program

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    printf("Only one print here\n");
    fork(); // executes a clone of the same process
    printf("my pid %d\n", getpid());
    for (int i = 0; i < 10; i++) {
        printf("from pid %d : %d\n", getpid(), i);
    }
    return 0;
}