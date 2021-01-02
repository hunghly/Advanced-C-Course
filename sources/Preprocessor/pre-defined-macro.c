#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /**
     * predefined macros and predefined symbolic constants
     * i.e. 
     * __FILE__ - represents the current file name (string)
     * __LINE__ - represents the current line number of the current source code (int constant)
     * __func__ - the name of any function placed inside a function of the current file (not part of the standard)
     * __DATE__ - the date the source file was compiled (string in the form of Mmm dd yyyy)
     * __TIME__ - the time the source file was compiled (string in form of hh:mm:ss)
     * __STDC__ - indicates 1 if compiler supports standard C
     **/

    printf("FILE %s\n", __FILE__);
    printf("LINE %d\n", __LINE__);
    printf("func %s\n", __func__);
    printf("DATE %s\n", __DATE__);
    printf("TIME %s\n", __TIME__);
    printf("STDC %d\n", __STDC__);

    FILE *fp = NULL;

    if ((fp = fopen("test.txt", "rw")) == NULL) {
        fprintf(stderr, "Failed to open file in %s at line %d\n", __FILE__, __LINE__); // prints out error/filename/line if file can't be found
    }
}