// timer.h
// functions provide output in various forms from the hardware timer in the PC
// time_t - Real type capable of representing times
// clock_t clock(void) - returns the processor time( not the elapsed time) used by the program since some implementation-defined reference point
// (often this is since execution time)
// you typically call clock() function at the start and end of some process in a program, the different is a measure of the processor time consumed by the process
// the processor time ist he total time the processor has been executing on behalf of the proces that called the clock() function
// the value that is returned by the clock() function is measured in clock ticks
// to convert this value to seconds, you divide it by the value that is produced by the macro CLOCKS_PER_SEC, returns -1 if an error occurs


// you can also use the time() function which returns the calendar time as a value of type time_t
// current time measured since 00:00:00 jan 1, 1970
// time_t time( time_t *arg ); -Returns the current calendar time encoded as a time_t object, and also stores it in the time_t object pointed to by arg (unless arg is a null pointer)
// to calculate elapsed time, you use difftime()
// double difftime( time_t time_end, time_t time_beg ); - this returns difference between end and beg in seconds
// returns -1 if end is before the beg

// getting the date
// char *ctime(const time_t *timer); 
// getting the local time
// struct tm *localtime  ( const time_t *timer );


#include <stdio.h>
#include <time.h>
// #include <threads.h>

int main(void) {
    // printf("%d\n",__STDC_VERSION__);
    clock_t start = clock();
    time_t t_start = time(NULL);
    printf("t is %lu\n", start);    

    clock_t end = clock();
    printf("t is %lu\n", end);
    printf("What is CPS? %d\n", CLOCKS_PER_SEC);
    double cpu_time = 0.0;
    printf("what is end - start? %lu\n", end - start);
    cpu_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("converted to seconds is %f\n", cpu_time);
    time_t t_end = time(NULL);
    printf("Time start is %lld\n", (long long) t_start);
    printf("Time end is %lld\n", (long long) t_end);
    printf("Time difference is %lld\n", (long long) difftime(t_end, t_start));
    return 0;
}