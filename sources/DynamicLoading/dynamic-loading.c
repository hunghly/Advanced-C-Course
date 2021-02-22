// used to load a binary or library while program is in runtime
// use dlopen() aka Dynamic Loading API
// header file <dlfcn.h>
// the dlopen() function opens a library and prepares it for use
// order matters
// void *dlopen(const char *filename, int flag);
// if filename begins with '/' i.e. an absolute path, dlopen() will just try to use it, otherwise
// it will search for the library in the LD_LIBRARY_PATH environemtn variable and other directories
// flag is either RTLD_LAZY or RTLD_NOW
// Lazy means to resolve undefined symbols as code from the dynamic library executed
// now means to resolve all undefined symbols before dlopen() returns and fail if this cannot be done
// the return of dlopen is a handle that should be used by the other DL library routines
// will return NULL if the attempt to load does not succeed (should check for NULL)
// if the same library is loaded more than once, it will return the same library


// dlerror() - returns a string describng the error from the last call to dlopen(), dlsym(), or dlclose()
// void* dlym(void* handle, char* symbol) - looks up the value/function of a symbol. this is what allows you to use the library
// - do not store the result of dlsym() into a void* pointer
// - you should cast it each time you use it
// converse of dlopen() is dlclose()
// call dlclose to deallocate library

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
// #include <math.h> // you could add math.h like this but that's done through compile time by linking


int main(void) {
    void *handle = NULL;
    double (*cosine)(double) = NULL;
    int (*checknan)(int) = NULL; // create a function pointer that will be assigned later
    char *error = NULL;
    handle = dlopen("/usr/local/lib/libImath.dyLib", RTLD_LAZY); // opens the library
    dlerror();
    if (!handle) {// check to see if dlopen return a null
        fputs(dlerror(), stderr);
        exit(1);
    }
    checknan = dlsym(handle, "isnan");
    cosine = dlsym(handle, "cos");
    char x = 'a';
    printf("Is X NaN? %d\n", checknan(x)); // you can now execute these symbols/functions with a dynamically loaded library
    printf("%f\n", (*cosine)(2.0));
    dlclose(handle);
    return 0;
}