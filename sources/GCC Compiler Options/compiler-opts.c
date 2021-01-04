/**
 * When you invoke GCC it normally does: 
 * 1. preprocessing, 
 * 2. compilation, 
 * 3. assembly, and 
 * 4. linking
 * i.e. C file ->preprocessing -> compiling -> assembly code -> assembler (.o file)->linker (to libaries) -> executable
 * some of the options to the compiler allow you to stop this process at an intermediate stage for example the -c option says not to run the linker
 * other options are passed on to one stage of processing, some options control the preprocessor and others the compiler itself,
 * other options control the assembler and linker
 * 
 * gcc program accepts options and file names as operands
 * 
*/