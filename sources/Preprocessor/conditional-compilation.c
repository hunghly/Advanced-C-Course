#include <stdio.h>

/**
 * The C preprocessor offers a feature known as conditional compilation
 *  -often used to create one program that can be compiled to run on different computer systems
 * If you had a large program that had many dependencies on specific hardware or software, you might end up
 * with many defines whose values would have to be changed when the program was moved to another computer system
 * you can help reduce this program by incorporating the values of these defines for each different machine into the program by using 
 * the conditional compilation capabilities of the preprocessor
 * 
 * it is also used to switch on or off various statements in the program
 * debugging statements that print out the values of various variables
 * trace the flow of program execution
 * 
 * conditional compilation enables you to control the execution of preprocessor directives and the compilation of program code
 * each of the conditional preprocessor directives evaluates an identifier or a constant integer expression
 * cast expressions, sizeof expressions, and enumeration constants cannot be evaluated in preprocessor directives
 * 
 * includes a set of commands that tell the compiler to accept or ignore blocks of information or coder according to conditions at the time of compilation
 * the conditional preprocessor construct is much like the if selection statement
 * every #if construct ends with an #endif
 * 
 * directives #ifdef and ifndef are shorthands or #if defined(name) and #if !defined(name)
 * multiple part conditional preprocessors constructs may be tested with #elif and #else
 */

// #ifdef checks whether an identifier is currently defined 

// #define UNIX 1
// #ifdef UNIX // if UNIX is defined, then compile all the code up to the else #else or #endif
//     #define LINUX 1
// #else
//     #define LINUX 0
// #endif

// #define JUST_CHECKING
#define LIMIT 4

// ifndef checks if the identifier is not currently defined
#ifndef SIZE
    #define SIZE 4 // defines size 4 if it's not defined
#endif

// if directive is used to test the value of a constant expression
// #if tests if a compile time condition is true, it does not contain any increment, decrement, sizeof, pointer, address or cast operators BUT
// you can use logical operators
#if SIZE == 4
    #undef SIZE
    #define SIZE 9
#endif

// #else to completement the ifdef and ifndef and if directives, the #else directive works just like an else statement
// it operates similar to C if else except the compiler does not recognize the braces
// These else-ifs can be nested
#ifdef UNIX
    #define DATADIR "/uxn1/data"
#else
    #define DATADIR "\usr\data"
#endif

//#elif is for multiple choice selections
#define US 0
#define UK 1
#define France 2
#define Germany 3
#define Country France

#include "just-checking.h"

int main(void) {
    #ifdef LINUX
        printf("Is Linux defined? %d\n", LINUX);
    #endif

    int i;
    int total = 0;
    for (i = 1; i <= LIMIT; i++) {
        total+= 2*i*i + 1;
        #ifdef JUST_CHECKING
            printf("i=%d, running total = %d\n", i, total);
        #endif
    }

    #if SIZE > 0 && SIZE < 10
        puts("Size less than 10 and greater than 0");
    #endif

    printf("SIZE IS %d\n", SIZE);

    #if Country == US || Country == UK
        #define Greeting "Hello."
    #elif Country == France
        #define Greeting "Bonjour"
    #elif Country == Germany
        #define Greeting "Guten Tag."
    #endif

    puts(Greeting);
}