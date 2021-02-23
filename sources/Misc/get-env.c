// an environment is an implementation-defined list of NAME/VALUE pairs maintained by the operating system
// the OS defines specific environment variables
// not all implementations necessarily define same set of environment variables
// - they must define same meanings to whatever environment variables they have
// the function getenv searches for the environment string that is passed in
// - it returns a null terminated string witht he value of the requested environment variable or NULL if that environment variable does not exist
// char *getenv( const char *name );

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    char *myvar = NULL;

    system("echo $HOME");
    myvar = getenv("HOME");
    
    assert(myvar != NULL);
    if (myvar != NULL) {
        printf("Your myvar is %s\n", myvar);
    }
    system("env");
    return 0;
}