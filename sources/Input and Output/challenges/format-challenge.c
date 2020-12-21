#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int isPrime(int x);

int main() {
    // take a set of numbers from a file and write even, odd, and prime numbers to standard output
    // use fscanf or (fgets and sscanf)
    FILE *fp = NULL;
    char *line = calloc(255, sizeof(char));
    int tmp;
    if ((fp = fopen("numbers.txt", "r")) == NULL) {
        fprintf(stderr, "Error opening your file\n");
    }
    
    while (fscanf(fp, "%s", line) == 1) {
        // puts(line);
        tmp = atoi(line);
        // printf("Line is %d\n", tmp);
        if (isPrime(tmp)) {
            printf("%d is Prime\n", tmp);
        } else if ((tmp % 2) == 0) {
            printf("%d is Even\n", tmp);
        } else {
            printf("%d is Odd\n", tmp);
        }
    }

    fclose(fp);


    return 0;
}

int isPrime(int x) {

    for (int i = 1; i < x; i++) {
        // printf("i: %d\n", i);
        if (i == 1 || i == 2 || i == x) {
            continue;
        }
        if ((x % i) == 0) {
            // puts("false");
            return false;
        }
    }
    return true;
}