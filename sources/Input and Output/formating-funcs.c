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

    return 0;
}