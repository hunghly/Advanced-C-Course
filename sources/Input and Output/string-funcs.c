#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * the gets function stands for get string and reads a string from stdin - reads until a newline or EOF is found
 * it does not read a size of characters which can cause an issue so it's not recommended for use
 * 
 * 
 * fgets is used for reading lines of data from a file/stream
 * char *fgets( char *restrict str, int count, FILE *restrict stream );
 * a null char is written immediately after the the last character is read
 * -it protects against overflowing the string
 * -it is deprecated because the function cannot tell whether a null character is included in the string it reads
 * -if a null character is read, it will store it in the string along with the rest of the characters read (only use
 * fgets if you know your data will not contain a null character)
 * 
 * 
 * getline is the latest function for reading a stirng of text and was added in 2010
 * the getline function is the preferred method to read lines of text since gets, fgets, scanf, are too unreliable
 * the getline function reads an entire line from a stream up to and including the next newline character and takes three parameters
 * ssize_t getline(char **lineptr, size_t *n, FILE *stream);
 * 
 * 1. 1st pointer is a ptr to a block allocated with malloc or calloc (type char **)
 *  -the address of the first char position where the input string will be stored
 *  -will automatically enlarge the block of memory as needed (realloc)
 *  -will contain the line read by getline when it returns
 * 2. 2nd param is a ptr to a variable of type size_t
 *  -specifies the size in bytes of the block of memory pointered to by the first parameter
 *  -the address of the variable that holds the size of the input buffer, another pointer
 * 
 * 3. 3rd param is the stream to read from
 * 
 * if an error occurs it returns -1 and sets feof or ferror on stream, otherwise returns num of chars stored in buffer but excludes null terminator
 * 
 * 
 * puts function is used to write a line to the output screen - automatically appends a new line
 * -simplier than printf since you dont need to include a newline character
 * the difference is that printf the argument is interpreted as a formatted string
 * int puts(const char *string);
 * 
 * fputs can designate a stream
 * int fputs( const char *restrict str, FILE *restrict stream );
*/
int main(void) {
    // char buf[255]; // create the array
    // int ch = '\0'; // make a char null char
    // char *p = NULL; // char pointer
    // printf("Enter some data: ");
    // if (fgets(buf, sizeof(buf), stdin)) {
    //     printf("Your buf is %s\n", buf);
    //     p = strchr(buf, '\n'); // gets the first occurence of newline
    //     if (p) {
    //         *p = '\0'; // set that location/address as a null pointer
    //     } else {
    //         while(((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin)); // this will continue to read characters until it reaches newline
    //     }
    // }

/*
    // GETLINE
    char *buffer = NULL;
    // char buffer[32];
    // char *b = buffer;
    size_t bufsize = 64;
    size_t characters;

    buffer = (char *) malloc(bufsize * sizeof(char));

    if (buffer == NULL) {
        exit(1);
    }

    printf("Type something: ");
    characters = getline(&buffer, &bufsize, stdin);

    printf("%zu characters were read.\n", characters);
    printf("You typed: '%s'\n", buffer);

*/
    char *str = {"Hello how are you?"};
    puts(str);

    FILE *fp = NULL;
    if ((fp = fopen("somefile.txt", "w"))) {
        if (fp == NULL) {
            exit(1);
        }
        
        fputs("Hello there!", fp);
    }
    fclose(fp);
    return 0;
}