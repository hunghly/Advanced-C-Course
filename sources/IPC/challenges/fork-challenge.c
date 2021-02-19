#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t parent;
    pid_t child1;
    pid_t child2;
    pid_t grandchild1;
    pid_t grandchild2;

    child1 = fork();
    if (child1 > 0) {
        printf("Inside child1\n");
        parent = getpid();
        printf("Parent is: %d\n", parent);
        child2 = fork();
        if (child2 > 0) {
            printf("Inside child2\n");
            parent = getpid();
            printf("Parent is: %d\n", parent);
        }
    }
    // child2 = fork();
    // printf("child 1 pid %d | child 2 pid %d\n", child1, child2);

    return 0;
}