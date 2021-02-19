#include <stdio.h>

inline void randomFunc() {
    
}

int main(void) {
    // normally a function call has overhead when being invoked (it takes time to set up the call, pass arguments, jump to function code, and return)
    // C99 added the concept of inline functions to try and avoid the amount of overhead that comes with invoking a function
    // the point is to advise the compiler that it is worth making some form of extra effort to call the function faster than it would otherwise (compiler does not need to listen)
    // usually the compiler will substitute the code of the function into it's caller (eliminating the need for a call and return sequence)
    // the program no longer calls that function, the compiler replaces every call to an inline function with the code body of that function

    // inline functions can improve the runtime performance of a program
    // it's a common misconception that in-lining always equals faster code
    // it can increase the size of the program since it is copied again and again in the program whereever it is called
    // it is suggested to only declare functions as inline if they are short and called frequently
    // for a long function, the time consumed in calling the function is short compared to the time spent executing the body of the function i.e. no great savings in time using an inline version

    // Declare an inline function by placing the keyword inlien before the function declaration
    // i.e. inline void randomFunction();
    // there are different places to create inline function definitions (same file or header file)
    // the inline function definition has to be in the same file as the function call (internal linkage)
    // should always use the inline function specifier along with the static storage-class specifier
    //  -usually defined before their first use in the file and also acts as a prototype
    // if you have a multi-file program, you need an inline definition in each file that calls the function OR just use a header file and put the header in each file
}