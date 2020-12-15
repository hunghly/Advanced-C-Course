#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    // write a program in C to count the number of words and characters in a file or from std input
    // char *filename = argv[1];

    // PART I
    // int wordC = 0;
    // int charC = 0;

    // if (filename) {
    //     FILE *fp1 = NULL;
    //     if ((fp1 = fopen(filename, "rw"))) {
    //         printf("Opened File!\n");
    //         int ch = 0;
    //         while ((ch = fgetc(fp1)) != EOF) {
    //             charC++;
    //             if (ch == ' ') {
    //                 wordC++;
    //             }
    //             fputc(ch, stdout);
    //         }
    //         wordC++;
    //     } else {
    //         printf("Error opening file..\n");
    //     }
    // } else {
    //     printf("Please enter text to be counted. End with Ctrl+D \n");
    //     int ch = 0;
    //     char *readInput;
    //     while ((ch = getchar()) != EOF) {
    //         charC++;
    //         if (ch == ' ') {
    //             wordC++;
    //         }
    //         // ungetc(ch, stdin);
    //     }
    //     wordC++;
    //     // fgets(readInput, charC, stdin);
    //     // printf("Your input: %s\n", readInput);
    // }

    // fclose(fp1);

    // printf("Word Count: %d | Char Count: %d\n", wordC, charC);

    //PART II
    // write a C program to convert uppercase to lower case and vice versa
    // can take a command-line argument for the name of the file or ask user to input the filename
    // create a temp file to store results and then rename temp file back to the original file
    char *filename = argv[1];

    // if file not provided, prompt for a file
    if (!filename) {
        filename = calloc(20, sizeof(char));
        printf("Enter a file to read from. Max len 20 chars.\n");
        scanf("%s", filename);
    }

    if (filename) {
        FILE *tar = NULL;
        FILE *temp = NULL;

        if ((tar = fopen(filename, "r")) && (temp = fopen("tmp.txt", "w"))) {
            int ch = 0;
            while ((ch = fgetc(tar)) != EOF) {
                printf("%c", ch);
                if (isupper(ch)) {
                    fputc(tolower(ch), temp);
                } else {
                    fputc(toupper(ch), temp);
                }
            }
        }
        else {
            printf("Error opening file.\n");
        }
        fclose(tar);
        fclose(temp);
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}