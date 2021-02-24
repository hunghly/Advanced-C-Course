#include <stdio.h>
#include <pthread.h>

struct date {
    int day;
    char* month;
    int year;
};

void printbday(struct date *bday) {
    printf("Your bday is %s %d,%d\n", bday->month, bday->day, bday->year);
}

int main(void) {
    struct date bestbday = {25, "December", 1000};
    struct date *dateptr = &bestbday;
    // printing normally
    printbday(dateptr);

    // printing with a thread
    pthread_t thread = 0;
    pthread_create(&thread, NULL, (void*) &printbday, dateptr);
    pthread_join(thread, NULL);
    pthread_exit(NULL);
    return 0;
}