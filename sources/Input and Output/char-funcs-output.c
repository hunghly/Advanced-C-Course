#include <stdio.h>

int main() {
    char ch = '\0';
    FILE *fp = NULL;
    FILE *fp2 = NULL;

    fp2 = fopen("out.txt", "w");

    if ((fp = fopen("test.txt", "rw"))) {
        ch = fgetc(fp);
        while (ch != EOF) {
            fputc(ch, fp2); // after reading the char, put it into the file
            ch = fgetc(fp); // get the next char
        }
    }
    fclose(fp);
    fclose(fp2);
    printf("\n");

    // char string[] = "Hello Jason, \n whatever!";
    // int i = 0;
    // while (string[i] != '\0') {
    //     if (string[i] != '\n') {
    //         putchar(string[i]);
    //     }
    //     i++;
    // }

    // int ch1 = 0;
    // while ((ch1 = getchar()) != EOF) {
    //     putchar(ch1); // put char to stdout
    //     ungetc(ch1, stdin); // ungetc returns EOF previously read back to std
    //     printf("Thank you!\n");
    // }

    // return 0;
}