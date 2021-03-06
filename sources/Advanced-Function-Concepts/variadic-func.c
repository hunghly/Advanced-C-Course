#include <stdio.h>
#include <stdarg.h>

double average(double v1, double v2, ...);

int main(void)
{
    // there is an unknown number of arguments for the function
    // typically use a variadic function when we do not know the total number of arguments that will be used for a function
    // could potentially have n number of args
    // a lot of C functions use variadic functions such as printf
    // the library <stdarg.h> provides you with routines to write some of your own variadic functions

    // a variadic function has two parts
    // a mandatory argument (at least one is required and it's the first one listed)
    // optional arguments (listed after mandatory arguments)
    // common practice is to have some number that will tell us how many arguments there are

    // when creating a function, you must understand how to reference the variable number of args
    // you do not know how many there are and cannot give them names
    // yu can solve this indirectly by using pointers

    // stdarg.h provides us with routines that are implemented as macros (look and operate like functions)
    // you need to use these when implementing your own function with a variable number of arguments

    // va_list used in situations in which we need to access optional paramters and it is an argument list
    // represents a data object used to hold the parameters corresponding to the ellipsis part of the parameter list

    // va_start will connect our argument list with some argument pointer
    // the list specified in va_list is the first argument and the second argument is the last fixed parameter

    // va_arg will fetch the current argument connected to the argument list. we would need to know the type of argument that we are reading

    // va_end used in situations when we would like to stop using are variable argument list (cleanup)

    // va_copy used in situations for which we need to save our current location
    double avg1 = average(10.0, 20.00, 30.0);
    double avg2 = average(20.0, 20.00, 30.0, 30.00);
    double avg3 = average(1.0, 2.00, 3.0, 4.0);
    double avg4 = average(10.0, 20.00);
    double avg5 = average(100.0, 200.00, 300.0, 400.00, 500.0, 600.00);

    printf("avg1: %f\n", avg1);
    printf("avg2: %f\n", avg2);
    printf("avg3: %f\n", avg3);
    printf("avg4: %f\n", avg4);
    printf("avg5: %f\n", avg5);

    return 0;
}

// provide a function prototype using an ellipsis(three dots)
// void f1(int n, ...);
// char f2(const char *s, int k, ...) // valid

// create a va_list type variable in the function definition
// initialize the variable to an argument list - need to copy the argument list to the va_list variable using va_start
double average(double v1, double v2, ...)
{
    va_list parg; // Pointer to the variable argument list

    va_start(parg, v2); // states that the first variable argument starts after v2, we still do not know what type of value those\
    arguments would represent

    // access the contents of the arg list using va_arg()
    // takes two arguments, a type va_list and a type name
    // each call gets the next item on the list
    double sum = v1 + v2;
    double value = 0.0;

    int count = 2; // initial amount of required arguments
    while ((value = va_arg(parg, double)) != 0.0)
    {
        sum += value;
        count++;
    }

    // you can clean up any lose ends by using va_end() which will reset the pargs pointer to NULL
    // takes in a va_list variable as it's argument
    va_end(parg); // cleanup

    return sum / count;
}