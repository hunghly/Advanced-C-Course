/** library - a collection of header files and implementation files,
 * exposed for use by other programs
 * -interface expressed in a header file/implementation expressed in a .cfile
 * -similar to an interface class in java and an implemented class
 * 
 * -library consists of one or more object files, which consists of object code
 * -c functions that can be shared by more than one application should be broken out of an application's source code
 * and compiled and bundled into a library
 * pros: 
 * librarys allow for fast compilation time
 * allows application vendors a way to simply release an API to interface with an application
 * libraries also allow for modular development and separation of components
 * software reuse
 * version management- can cohabitate old and new versions on a single system
 * specialized developers can focus on their core competency on a single library
 * 
 * when c program is compiled it generates object code (.o)
 * after generating the object code, the compiler also invokes the linker
 * linking is the process of collecting and combing multiple object files in order to create a single executable file (combine into one executable)
 * 
 * a linker does two things:
 * 1. (static linking) copies the code of the library function to your object code
 * 2. (dynamic linking) or by making some arrangements so that the complete code of library functions is not copied but made availabe at run-time
 * 
 * static linking - the code is pulled into the code and is part of the application
 * - advantage is speed, there is no symbol resolution at runtime
 * - every piece of the library is part of the binary image (executable)
 * - if something is not installed on the system (i.e. a library) it will be ok, because you have it in your application
 * - creates larger binary file and utilizes more disk space
 * - once library is linked and program is created, you have no way of changing of the library code without rebuilding the whole program
 * 
 * dynamic linking - defers much of the linking process until program starts running
 * - libraries are loaded into memory by programs when they start
 * - during compilation of library, the machine code is stored on your machine (only the new code in the program is compiled)
 * - the main reason for using dynamic linking of libraries is to free your software from the need to recompile with each new release of a library
 * - much smaller executable size
 * - trades off more efficient use of disk space and quick linker phase for a small runtime penalty
 * - improves performance in two ways
 *  1. saves on disk and virtual memory
 *  2. all executables dynamically linked to a library share a single copy of the library at runtime
 * 
 * Library types:
 * Two types of C library types
 * 1. static libraries (.a file)
 * - uses static linking
 * - each process gets its own copy of the code and data
 * - known as an archive
 * 2. share object libraries (.so file)
 * - dynamically linked at runtime
 * - shared objects are not included in the executable component but are tied to execution
 * - code shared, data is specific to each process
 * 
 * static libraries are called something.a or something.lib
 * dynamic libraries are called something.so
 * 
 * you can identify your libraries by looking at the header files you have used
 * - each header file that you include potentially represents a library against which you must link
*/