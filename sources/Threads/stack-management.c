#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
// POSIX standard does not dictate the size of a thread's stack - implementation dependant and varies
// exceeding the default stack limit is often very easy to do 
// this results in program termination and data corruption
// safe and portable programs do not depend upon the default stack limit
// - instead, explicitly allocate enought stack for each thread by using the pthread_attr_setstacksize function
// you can get the stack size with pthread_attr_getstacksize(attr, stacksize)

//int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
//int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize);


// pthread_equal and pthread_once
// pthread_equal function compares two thread id's - returns 0 if they are different, otherwise non-zero is returned
// should not use == to compare

// pthread_once executes the init_routine exactly once in process
// the first call this function by any thread in the process executes the given init_routine, without parameters
// any subsequent call will have no effect
// pthread_once(once_control. init_routine);
// init routine is typically an initization routine
// the once_parameter is a synchronoization control structure that requires initialization prior to calling pthread_once
// - pthread_once_t once_control = PTHREAD_ONCE_INIT

pthread_attr_t attr;

void* dowork(void *threadid) {
    long tid;
    size_t mystacksize;
    tid = (long) threadid;
    pthread_cancel(pthread_self());
    pthread_attr_getstacksize(&attr, &mystacksize);
    printf("Thread %ld: stack size = %li bytes\n", tid, mystacksize);

    pthread_exit(NULL);
}


int main(void) {
    pthread_t myThread;
    size_t stacksize;
    pthread_t myID;
    long t = 5;

    pthread_attr_init(&attr); // initializes the global pthread attribute
    pthread_attr_getstacksize(&attr, &stacksize); // get the current stack size from attr and store into stack size
    printf("stack size is %zu\n", stacksize);
    // dowork();
    stacksize = 9000000;
    printf("Amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setstacksize(&attr, stacksize); // assigns attr with value of stacksize
    printf("Creating thread with stack size %li\n", stacksize);
    myID = pthread_create(&myThread, &attr, dowork, (void*)t);
    printf("myID is %d\n", myID);
    if (myID) {
        perror("Error creating thread\n");
        exit(1);
    }
    pthread_exit(NULL);
    return 0;
}