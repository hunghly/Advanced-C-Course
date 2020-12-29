/**
 * The preprocessor operator includes 4 operators
 * 1. \ - allows for continuation of line
 * 2. defined - the define() operator is used in constant expressions to determine if an identifier is defined using #define
 * 3. # - when used in a macro definition, it is used for replacing the text token into a string 
 * surrounded by quotes
 * 4. ## - used for concatting. when expanded the tokens on each side are combined
 * 
*/

#include <stdio.h>

#define THIS_IS_DEFINED
int main(void) {
    #if defined(THIS_IS_DEFINED)
        puts("Hello There!");
    #endif
}
