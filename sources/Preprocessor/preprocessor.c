
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