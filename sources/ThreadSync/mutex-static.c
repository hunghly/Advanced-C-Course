#include <stdio.h>
#include <pthread.h>

#define NTHREADS 10

void *thread_function(void*);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; // initializes mutex default values

int counter = 0;

int main(void) {
    pthread_t thread_id[NTHREADS]; // create NTHREADS of threads
    int i, j;

    for (i = 0; i < NTHREADS; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, NULL); // create each thread
    }

    for (j = 0; j < NTHREADS; j++) {
        pthread_join(thread_id[j], NULL);
    }

    printf("Final counter value: %d\n", counter);
    return 0;
}

void *thread_function(void *dummyPtr) {
    printf("Thread number %ld\n", pthread_self());
    pthread_mutex_lock(&mutex1); // lock the threads from accessing this function
    printf("You only see this if function is unlocked\n");
    counter++;
    pthread_mutex_unlock(&mutex1);
    // return NULL;
    pthread_exit(NULL);
}