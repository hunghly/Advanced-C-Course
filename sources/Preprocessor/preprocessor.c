
/**
 * preprocessor, complication, assembler, linker, loader
 * a program called the preprocessor is invoked BEFORE any code gets compiled in the C programming language
 * it is a sepearate step in the compilation process and is not part of the compiler
 * the C Preprocessor (essentially a text substitution tool) instructs the compiler to do required pre-processing before the actual compilation
 * it mainly performs three tasks on your code
 * 1. removes all the comments
 * 2. includes all the files from various libraries that the program needs to compile
 *  -i.e. #include directive includes the contents of the library file specified
 * 3. expansion of macro definitions
 * 
 * All preprocessor directives begin with a '#' symbol
 * Conditional compilation commands
 * - #ifdef, #ifndef, #if, #elif, #else, #endif
 * Other directives
 * - #undef, #pragma, #error
 * 
 * continuation operator(\)
 * concat operator
 *  -(#) when used within a macro definition converts macro parameter into a string constant
 *  -(##) when used within a macro definition combines two arguments - permits two separate tokens in the definition to be joined into a single token
 * defined()
 *  -simplifies the writing of compound expressions in certain macro directives
*/
#include <stdio.h>


#define str(x) #x   // this will cause whatever is passed into as x to be wrapped with double quotes and treated as a string
#define Hello(x) printf("Hello," #x "\n")
#define printint(var) printf(# var"=%i\n", var) // space is optional between # and var name

// the ## operator is used in macro definitions to join two tokens together
// - preceded or followed by the name of a parameter to the macro
// - takes the actual argument to the macro that is supplied when the macro is invoked and creates a single token out of that argument and whatever token follows/preceds the ##
// two tokens that don't together form a valid token cannot be pasted together i.e. cannot concat x with +
#define TOKENCONCAT(x,y) x ## y // TOKENCONCAT(O,K) is replaced by OK in the program
#define concatenate(x,y) x##y // combines x and y into one string xy when passed into argument
#define make_function(name) int my_## name (int foo)

#define eat(what) puts("I'm eating " #what " today.")

int main(void) {
    puts(str(testing)); // check macro definition
    Hello(Hung);
    int count = 3;
    printint(count); // passes the var name and the var value
    int xy = 10;
    printf("%d\n", concatenate(x,y));
    // printf("%s", concatenate(10,10));
    char bar[] = {"bar"};
    make_function(bar); // will define a function called my_bar()
    eat(fruit);
}