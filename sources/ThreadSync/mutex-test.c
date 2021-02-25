#include <stdio.h>
#include <pthread.h>

// the threads library (pthread.h) provides three synchronization mechanisms that we can implement
// mutexes - locks, blocks access to variables by other threads
// joins - makes a thread wait til others are completed (terminated)
// condition variables - a way to communicate to other threads
// joins are useful for allowing the programmer to collect all relevant threads at a logical sync point

int main(void) {
    // mutexes are locks
    // very open the action performed by a thread owning mutex is the updating of a global variable
    // a safe way to ensure that when several threads update the same variable, the final value is the same as what it would be if only one thread performed the update
    /*
    Mutex sequence example
    1. create and initialize mutex
    2. threads attempt to lock the mutex
    3. only one succeeds and owns the mutex
    4. that owner thread performs work then unlocks mutex
    5. another thread acquires the mutex and repeats the process
    6. when done, mutex is destroyed
    ** deadlocks can occur, we need to make sure threads acquire locks in an agreed order (preservation of locking order)
    
    int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
    int pthread_mutex_destroy(pthread_mutex_t *mutex);
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    
    */
   // two ways to create/initialize mutex
   //1. statically when it is declared
   pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // initialize to default pthread mutex values
   //2. dynamically, with the pthread_mutex_init function
   // 

    return 0;
}