#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // write a program that takes two command line arguments, the first is a char, the second is a filename
    // print out only those lines in the file containing that given character
    // lines in a file are identified by a terminating '\n'
    // assume that no line is more than 256 chars long
    if (argc < 3) {
        puts("Please enter a format with '<cmd> <char> <filename>'");
        exit(1);
    }
    
    char ch = (char)argv[1][0]; // get just the first char in the string ptr
    char *filename = argv[2]; // get filename
    char *line;
    FILE *fp = NULL;
    size_t line_size = 32;

    if ((fp = fopen(filename, "r"))) {
        while (getline(&line, &line_size, fp) != -1) {
            if (strchr(line, ch) != NULL) {
                printf("%c found in %s\n", ch, line);
            }
        }
    }
    return 0;
}