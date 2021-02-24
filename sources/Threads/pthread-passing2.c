#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *hello_return(void* args) {
    // allocate a new string on the heap with "Hello World!"
    char* hello = strdup("Hello World!\n"); // strdup -duplicates the string Hello World into hello
    return (void*) hello; // returns a void* to the address of hello
}
int summation(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    sum+=i;
  }
  return sum;
}

int main(int argc, char*argv[]) {
    char* str;
    pthread_t thread;

    // create a new thread that runs hello return without arguments
    pthread_create(&thread, NULL, hello_return, NULL);
    pthread_join(thread, (void**) &str);
    // pthread_exit(NULL); // if we try to exit here, the pthread_join will not be able to return the pointer to address of hello
    printf("%s\n", str);
    printf("%d\n", summation(8));
    return 0;
}

