/** the functions that comprise the pthreads API can be grouped into three major categories
1. thread management
-routines that work directly on threads - creating, detaching, joining, etc.
-also includes functions tos et/query thread attributes (joinable, scheduling etc.)

2. synchronization
-routines that manage read/write locks and barriers and deal with synchronization
-mutex functions provide for creating,d estroying, locking, and unlocking mutexes (mutural exclusion)

3. condition variables
-routiens that address communicaitons between threads that share a mutex
-based upon programmer specified conditions

operations that can be performed on threads include:
-thread creation
-termination
-synchronization
-scheduling
-data management
-process interaction

creating a thread
-the lifecycle of a thread, much like a process, begins with creation
-threads are not forked from a parent to a child
-instead they are simply created with a starting function ast he entry point
-<pthread.h>
-main function is the initial thread, all other threads must be created by programmer
-once created. threads are peers and may create other threads. no implied hierarchy or dependency between threads
-max threads is implementation dependent.

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    void *(*start_routine)(void*), void *arg);

-takes four arguments
1. type pthread_t - an int used to identify the thread
2. specifies attributes for the thread
3. name of the function that the thread will execute once created
4. pass arguments to that function

pthread_join
-useful to be able to identify when a thread has completed or exited
-join the thread which is performed when one wants to wait for a thread to finish
-i.e. used to link the current thread process to another thread
-a thread calling routine may launch multiple threads then wait for them to finish to get the results
-a call to pthread_join blocks the calling thread until the thread with the identifier equal to the first argument terminates (makes the thread wait)
-the pthread_join() also receives the return value of your thread function and stores it in a void pointer variable

int pthread_join(pthread_t thread, void **value_ptr);

pthread_exit()
-threads can terminate by calling pthread_exit, letting the thread function return, or by calling to a function exit which will terminate the process including any threads
-typically pthread_exit() is called after work is done

void pthread_exit(void *value_ptr);
-sometimes it is desirable for a thread not to terminate (i.e. a server with a worker thread pool)
-can be solved by placing a thread code in an infinite loop and use condition variables

*/

#include <stdio.h>
#include <pthread.h>

void *hello_fun() {
    printf("Hello World!\n");
    return NULL;
}

void print_name(char* name) {
    printf("Hello %s\n", name);
}

int main(void) {
    pthread_t thread; // create thread variable
    pthread_t thread2;
    char* myname = {"Hung"};
    pthread_create(&thread, NULL, hello_fun, NULL); // create the thread passing in it the thread, any attributes (right now NULL), the function, and any arguments)
    pthread_create(&thread2, NULL, (void*)&print_name, myname); // creating a thread and passing in arguments

    // if we do not join threads, main function will exit before thread finishes work
    pthread_join(thread, NULL);
    pthread_join(thread2, NULL);

    pthread_exit(NULL);

    return 0;
}