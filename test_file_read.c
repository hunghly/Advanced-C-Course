#include <stdio.h>

int main(void) {

    char *content = "This is my content";

    FILE *fp = NULL;
    int ch;
    int i = 0;
    if ((fp = fopen("my_test_file.txt", "w"))) {
        while ((ch = content[i]) != '\0') {
            fputc(ch, fp);
            putchar(ch);
            i++;
        }
    }
    fclose(fp);

    return 0;
}