#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/*
pthread_detach - when a thread is created, one of its attributes defines whether it is joinable or detached
- by default if you pass NULL as the second argument the thread will be in joinable state
- only threads that are created as joinable can be joined
- **if a thread is created as detached, it can never be joined**
- if you know in advance that a thread will never need to join with another thread, consider creating it in a detached state *potentially freeing up some system resources*

-two common cases of when to detach
-in a cancellatin handler for a pthread_join()
    -nearly essential to have a pthread_detach() function in order to detach the thread on which pthread_join was waiting
-in order to detach the "initial thread" (as may be desirable in processes that set up server threads)
-pthread_detach() routine can be used to explicitly detach a thread even though it was created as joinable

int pthread_detach(pthread_t thread);

*/

void *calls(void* ptr) {
    // call pthread_self() to get current thread id
    printf("in func, thread id=%d\n", (int) pthread_self());
    pthread_exit(NULL);
    return NULL;
}

void *threadFn(void *arg) {
    pthread_detach(pthread_self()); // storage for the thread can be reclaimed when the thread terminates
    sleep(1);
    printf("Thread Fn\n");
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    pthread_t thread;
    pthread_create(&thread, NULL, calls, NULL);
    printf("main thread id=%d\n", (int) pthread_self()); // main thread
    pthread_join(thread, NULL);

    pthread_t tid;
    int ret = pthread_create(&tid, NULL, threadFn, NULL);

    printf("ret is %d\n", ret);

    if (ret != 0) {
        perror("Thread Creation Error\n");
        exit(1);
    }

    printf("After thread created in Main\n");
    pthread_exit(NULL);

    return 0;
}