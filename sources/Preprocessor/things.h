#ifndef THINGS_H_
    #define THINGS_H_
    // rest of include file

    // the definition of the first header file included becomes the active definition and subsequent definitions in other header files are ignored
    // the first time the preprocessor encounters this include file, THINGS_H_ is undefined, so the program proceeds to define THINGS_H_ and to process the rest of the file
    // the next time the preprocessor encounters this file, THINGS_H_ is defined so the preprocessor skips the rest of the file
    // it ensures that the contents of a header file cannot be included more than once into a source file
#endif