#include <stdio.h>

// the #pragma directiev lets you place a compiler instruction in your source code
// lets you request special behavior from the compiler
// this directive is most useful for programs that are unusually large or that need to take advantage of the capabilities of a particular compiler
// #pragma can be used to
// 1. control the amount of memory set aside for automatic variables
// 2. to set the strictness of error checking
// 3. to enable nonstandard language features

// the pragma (pragmatic information) directive is part of the standard
// the meaning of any pragma depends on the software implementation of the standard that is used
// generally, each compiler has its own set of pragmas

// an example to turn on C9X support was #pragma c9x on
// the syntax is #pragma token_name
// there is only a limited list of supported tokens for each standard/compiler

// #pragma GCC dependency
// allows you to check the relative dates of the current file and another file, if the other file is more recent, a warning is issued
// this pragma is useful if the current file is derived from the other file, and should be regenerated
// #pragma GCC dependecy "parse.y"

// Sometimes, there is an identifier that you want to remove completely from your program, and make\
 sure that it never creeps back in. To enforce this, you can poison the identifier with this pragma.\
  #pragma GCC poison is followed by a list of identifiers to poison. If any of those identifiers appears anywhere \
  in the source after the directive, it is a hard error.

// #pragma GCC poison printf sprintf fprintf // this will cause an error when you do any of these functions

// #pragma GCC system_header tells the compiler to consider the rest of the current include file as a system header
// system headers are header files that come with the OS or compiler
// this pragma can affect the severity of some diagnostic messages
// all warnings are suppressed while GCC is processing a system header and macros defined in a system header are immune to a few warnings whenever they are expanded

// #pragma GCC warning and #pragma GCC error
// #pragma GCC warning "message" causes the preprocessor to issue a warning with the text "message"
// similar the error issues a "message" for errors
#pragma GCC warning "Don't do it!"
// #pragma GCC error "You broke it!" // will cause the program to not compile

// #pragma once - specifies that the header file containing this directive is included only once even if the programmer includes it multiple times during a compilation
// works similar to using include guards and is a less-portable alternative to using #ifndef to guard the contents of header files against multiple inclusions

// #pragma message "message" - issues a message
#pragma message "This is only for information"

// #error directive - one of the least used but potentially most useful features of the C preprocessor is the ANSI-specified #error directive
// the #error directive causes the preprocessor to issue an error message that includes any text in the directive
// error message is a sequence of characters separated by spaces, you do not need to have them enclosed in quotes, messages are optional
// THIS DIRECTIVE CAN BE USED FOR CODE THAT COMPILES BUT IS STILL INCORRECT
// IT WILL COMPILE THE CODE AND EXECUTE AND GENERATE THE ERROR
#if __STDC_VERSION__ != 201112L // should fail if the compiler used is an older standard and success when it's using C11
    #error NOT C11
#endif

// #warning message - issue a warning
#warning this is a warning
// #line preprocessor directive is used to set the filename and the line number of the line following the directive to new values

int main(void)
{
    printf("Hello world!\n");
    puts("Hello Back!");
    printf("%d", __STDC_VERSION__);
    #error generating error but still compiles
}