#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    // write a program in C to count the number of words and characters in a file or from std input
    char *filename = argv[1];

    int wordC = 0;
    int charC = 0;

    if (filename) {
        FILE *fp1 = NULL;
        if ((fp1 = fopen(filename, "rw"))) {
            printf("Opened File!\n");
            int ch = 0;
            while ((ch = fgetc(fp1)) != EOF) {
                charC++;
                if (ch == ' ') {
                    wordC++;
                }
                fputc(ch, stdout);
            }
            wordC++;
        } else {
            printf("Error opening file..\n");
        }
    } else {
        printf("Please enter text to be counted. End with Ctrl+D \n");
        int ch = 0;
        char *readInput;
        while ((ch = getchar()) != EOF) {
            charC++;
            if (ch == ' ') {
                wordC++;
            }
            // ungetc(ch, stdin);
        }
        wordC++;
        // fgets(readInput, charC, stdin);
        // printf("Your input: %s\n", readInput);
    }

    

    printf("Word Count: %d | Char Count: %d\n", wordC, charC);

    return 0;
}