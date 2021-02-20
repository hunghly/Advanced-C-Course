#include <stdio.h>
#include <stdlib.h>

/**
 * qsort standard library function is designed to sort an array by a key value of any type into ascending order
 * as long as any type into ascending order
 * void qsort( void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *) );
 * arguments:
 * @param ptr - the array to be sorted
 * @param count - the number of elements in the array
 * @param size - the size of each element in the array in bytes
 * @param comp the comparision function which returns a negative int value if the first arg is < second arg
 *
 */

typedef struct {
    int key;
    char* other_data;
} record;

// create the compare function, similiar to comparator in java
int record_compare(void const *a, void const *b) {
    // cast record and get the key then do comparision
    return (((record*)a)->key - ((record*)b)->key);
}

void printrecord(record record) {
    printf("Record key: %d\n", record.key);
    printf("Record data: %s\n", record.other_data);
}

#define SIZE 3

int main(void) {

    record* records = malloc(SIZE * sizeof(record)); // create an array of 3 records
    for (int i = SIZE-1; i >= 0; i--) {
        records[i].key = i;
        records[i].other_data = "something";
        printrecord(records[i]);
    }
    printf("\n--------sorting--------\n");
    qsort(records, SIZE, sizeof(record), record_compare);
    for (int i = 0; i < SIZE; i++) {
        printrecord(records[i]);
    }


    return 0;
}

