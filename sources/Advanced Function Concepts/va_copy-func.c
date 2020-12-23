#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void sayHello(char *name, ...);
double sample_stddev(int count, ...);

int main(void) {
    // va_arg() does not provide a way to back up the previous arguments
    // it is possible that you may need to process a variable argument list more than once
    // it is useful to preserve a copy of the va_list type variable
    // use va_copy() - two arguments are both type va_list variables that will copy the second argument to the first
    // the va_copy copies the list exactly as the state it is in, so if you used/extracted some arguments from the original\
    they will be missing from the copy
    // do not use the va_list copy as the destination for another copy operation before you executed va_end for pa_copy

    sayHello("Hung", "Ly");
    return 0;
}


double sample_stddev(int count, ...) {
    double sum = 0;
    va_list args1;
    va_start(args1, count);
    va_list args2;
    va_copy(args2, args1); // makes a copy which is independent of previous arg1

    for (int i = 0; i < count; i++) {
        double num = va_arg(args1, double);
        sum += num;
    }
    va_end(args1); // make sure to end the first list before using copy
    double mean = sum / count;
    double sum_sq_diff = 0;

    for (int i = 0; i < count; i++) {
        double num = va_arg(args2, double);
        sum_sq_diff += (num - mean) * (num - mean);
    }
    va_end(args2);
    return sqrt()
}

void sayHello(char *name, ...) {
    va_list pargs, pargs_copy;
    va_start(pargs, name);
    char *value = calloc(25, sizeof(char)); // allocate 25 chars for the name args
    while ((value = va_arg(pargs, char*)) && (strcmp(value, "") != 0)) {
        puts(value);
    }
    // value = va_arg(pargs, char*);
    // puts(value);
    va_end(pargs);
}