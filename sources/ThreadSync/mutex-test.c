#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock = NULL; // create mutex variable
int j = 0;

void do_process() {
    pthread_mutex_lock(&lock); 
    int i = 0;
    j++;

    while (i < 5) {
        printf("%d",j);
        sleep(1);
        i++;
    }
    printf("Done....\n");
    pthread_mutex_unlock(&lock);
}

int main(void) {
    int err = 0;
    pthread_t t1, t2;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        
    }
    return 0;
}