// the ifndef directive is commonly used to prevent multiple inclusions of a file
// many include files include other files, so you may include a file explicity that another include file has already included
// this is a problem sinc some items that appear in include files such as declaration of struct types, can appear only once in a file
// prevents multiple definitions of the same variable/function/macro
// the standard C header files uses the #ifndef technique to avoid multiple inclusions
// one problem is to make sure the identifier you are testing has not been defined elsewhere
// using the filename as the identifier (using uppercase, replacing periods with an underscore, and using an underscore)

#ifndef _STDIO_H
#define _STDIO_H
// contents of the file
#endif

// undef is another flexibility that you have with preprocessor directives to undefine an identifer you have previously defined
// #undef name 

