#include <stdio.h>
#include <stdlib.h>

#define MAX 41

int main(void) {
    // sprintf() used to write formatted output to a string
    // int sprintf( char *restrict buffer, const char *restrict format, ... );
    char *myStr = calloc(100, sizeof(char));
    sprintf(myStr, "Hello %s! It's %s the %d!", "Hung", "December", 18);
    // puts(myStr);
    // sprintf is unsafe because it doesn't check the length of the destination buffer
    // fprintf is the same as printf but prints to a file stream
    FILE *fp = NULL;
    char ch_buf[100];

    if ((fp = fopen("format_test.txt", "wr")) != NULL) {
        fprintf(fp, "The string we will write is: %s\n", myStr);
    } else {
        // puts("Error opening file.");
        // instead you can use fprintf and stderr
        fprintf(stderr, "Unable to open file.");
        exit(1);
    }
    fclose(fp);

    // fprintf and stderr usage
    // you can use fprintf and stderr together to print to the terminal

    // fscanf is provided to perform the same operations as the scanf() function but on a file
    // int fscanf( FILE *restrict stream, const char *restrict format, ... );


/*
fscanf
    FILE *fp1 = NULL;
    char buff[254];
    char words[MAX];

    if ((fp1 = fopen("data.txt", "a+")) == NULL) {
        fprintf(stderr, "Cannot open file\n");
        exit(EXIT_FAILURE);
    }


    // while (fscanf(fp1, "%s", words) != EOF) { // will read a string into the buffer, buff
    //     printf("%s ", words);
    // }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
        fprintf(fp1, "%s\n", words);
    }

    puts("File contents:");
    rewind(fp1);

    while (fscanf(fp1, "%s", words) != EOF) { // will read a string into the buffer, buff
        puts(words);
    }

    puts("Done");

    fclose(fp1);
    */

    // sscanf reads from a string rather than reading from standard input or keyboard
    // int sscanf( const char *restrict buffer, const char *restrict format, ... );

    // the first argument is a pointer to the string from where we want to read the data
    // the rest of the arguments of sscanf is same as that of scanf
    // returns the number of items read from the string and -1 if an error is encountered

    char *myStr1 = "Jason Instructor 43";

    char name[30], title[30];
    int age = 0, ret = 0;

    ret = sscanf(myStr1,"%s %s %d", name, title, &age); // basically it parses the string and assigns it to individual variables
    printf("Name is %s\n", name);
    printf("title is %s\n", title);
    printf("Age is %d\n", age);

    // fflush function is used to flush/clean a file or buffer
    // causes any unwritten data in the output buffer to be sent to the output file 
    // int fflush(FILE *fp);
    // fflush (buffer);
    // buffer is a temp variable or pointer which loads/points to the data
    // if the file is a null pointer, all output buffer are flushed
    // the effect of using fflush() on an input stream is undefined
    // you cna use it with an update stream (any of the read-write modes), provided that the most recent operation useding the stream was not input
    


    return 0;
}