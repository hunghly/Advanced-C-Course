#include <stdio.h>
#include <string.h>


// a void pointer is a pointer that points to a value that has no type
// represents a lack of a type
// void pointers can point to a variable of any data type - from int to float to chars

struct bio {
    int height;
    int weight;
    char* birthday;
};


struct person {
    char *name;
    struct bio data;
};

void send_data(void *pData, int nLength);

int main(void) {

    void *vp;

    int a = 100, *ip;
    float f = 12.2, *fp;
    char ch = 'a';

    // vp is a void pointer so you can assign it the address of any type of variable to it
    vp = &a; // ok
    printf("vp is: %d\n", *(int*)vp); // must cast to an int* and then dereference
    vp = &f; // ok
    printf("vp is: %f\n", *(float*)vp);
    vp = &ch; // ok
    printf("vp is %c\n", *(char*)vp);

    struct person joe;
    struct person *joeptr;
    joeptr = &joe;
    // joe = (person) {.name = "joe johnson", { 70, 170, "jan 1, 2020" }};
    joe.name = "joe johnson";
    joe.data = (struct bio) { 70, 170, "jan 1, 2020" };
    printf("joe's name: %s\n", joe.name);
    printf("joe's name using ptr: %s\n", joeptr->name);
    printf("joe's height %d\n", joeptr->data.height);
    printf("joe's weight %d\n", joeptr->data.weight);
    printf("joe's birthday %s\n", joeptr->data.birthday);


    char * data = "some data as a string";
    
    send_data(data, strlen(data));

    void *pvData = NULL;
    int *iData = NULL;
    char *cData = NULL;
    float *fData = NULL;

    // all pointers are 8 bytes regardless of type
    printf("size of data %d\n\n", sizeof(pvData));
    printf("size of data %d\n\n", sizeof(iData));
    printf("size of data %d\n\n", sizeof(cData));
    printf("size of data %d\n\n", sizeof(fData));

    return 0;
}

void send_data(void *pData, int nLength) {
    printf("Your pointer is %s\n", (char*) pData);
}
