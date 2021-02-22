#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int count_chars(char* str, char ch) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

char* removeAlphabet(char* str) {
    char* removed = malloc(sizeof(char) * strlen(str));
    int lastPos = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
           removed[lastPos] = str[i];
           lastPos++;
        }
    }
    removed[lastPos] = '\0';
    return removed;
}

int calcLength(char* str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length+1;
}

