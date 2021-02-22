#include <stdio.h>
#include "../headers/StringFunctions.h"

int main(void) {
    char* word1 = "hello Worlde";
    char ch = 'e';
    int count;
    count = count_chars(word1, ch);
    printf("count is %d\n", count);
    printf("removed = %s\n", removeAlphabet(word1));
    printf("length is %d\n", calcLength(word1));
}