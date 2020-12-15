#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // originally in/output functions were not a part of C, their development was left to C implementations, the Unix implementation of C has servered as a model for these functions
    // we focus on the standard I/O functions available on all systems that enable us to write portable programs that move easily from one system to another
    // when a C program is executed three files are automatically opened by the system for use by the program
    /*
    *   They are:
    * 1. stdin
    * 2. stdout
    * 3. stderr
    * all defined in <stdio.h>
    * -all standard I/O functions that perform input and do not take a FILE pointer as an argument get their input from stdin
    * -stdout refers to the standard output which is the terminal normally
    * -stderr identifies the standard error file which is also normally associated with the terminal
    */

    /*
   * getc
   * int getc(FILE *stream);
   */

    char ch = '\0';
    FILE *fp;

    if ((fp = fopen("test.txt", "rw")))
    {
        ch = fgetc(fp);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(fp);
        }
        fclose(fp);
    }


    printf("\n");
    ch = getc(stdin); // reading from stdin/terminal by default
    printf("read in char %c\n", ch);

    // using getchar()
    // int ch1 = 0;
    // while ((ch1 = getchar()) != EOF) {
    //     printf("%c", ch1);
    // }

    char ch2 = 0;
    while (isspace(ch2 == (char)getchar())) {
        ungetc(ch, stdin);
    }

    printf("char is %c", getchar());



    return 0;
}