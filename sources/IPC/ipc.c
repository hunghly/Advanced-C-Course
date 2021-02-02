

int main(void) {
    // a process is a program in execution
    // a program is a file containing the information of a process
    // each process has its own address space and usually one thread of control unlike threads that share address space
    // you can have multiple processess executing the same program, but each process has ites own copy of the program within its own address space i.e. two open word documents do not share variables
    // a process created by a given parent are called child processes and a child can inherit many of it's attributes from the parent process
    // each process is identified with a unique positive integer called a process id (PID)
    // the system call getpid() returns the process IDof the calling process
    return 0;
}