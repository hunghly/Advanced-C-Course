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
    
    Initializing
    int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
    int pthread_mutex_destroy(pthread_mutex_t *mutex);
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    
    Locking
    int pthread_mutex_lock(pthread_mutex_t *mutex);
        -used by thread to acquire a lock on the specified mutex variable
        -if mutex is already locked by another thread, this call will block the calling thread until the mutex is unlocked
    int pthread_mutex_trylock(pthread_mutex_t *mutex);
        -will attempt to lock a mutex, however, if the mutex is already locked, the routine will return immediately with a "busy" error code
        -may be useful in preventing deadlock conditions, as in a priority-inversion situation
    int pthread_mutex_unlock(pthread_mutex_t *mutex);
        -unlocks a mutex, call this after a thread has completed using the protected data
        -error will be returned if mutex is already unlocked or if mutex is owned by another thread
    */
   // two ways to create/initialize mutex
   //1. statically when it is declared
   pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // initialize to default pthread mutex values
   //2. dynamically, with the pthread_mutex_init function
   // this function requires a pthread_mutex_t variable to operate on as a first argument
   // attributes for the mutex can be given through the second parameter
   // -to specificy default attributes, pass NULL as the second parameter

   // the pthreads standard defines three optional mutex attributes
   // - protocol - specifies the protocol used to prevent priority inversions for a mutex
   // - prioceiling - specifies the priority ceiling of a mutex
   // - process-shared -specifies the process sharing of a mutex
   // pthread_mutex_destroy(mutex) can be used to free the mutex when finished
   // to 
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }
   pthread_mutex_lock(&lock);
   printf("soemthing here");
   pthread_mutex_unlock(&lock);

    return 0;
}