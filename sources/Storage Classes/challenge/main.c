#include <stdio.h>

int sum(int num);
void display();

static double insidefile = 10.00;
float accessanywhere = 13.50;
int counter = 10;

int main(void) {
    int blocktemp = 10;
    static float permStorage = 8.00;
    register int reg1 = 15;

    printf("%d ", sum(25));
    printf("%d ", sum(15));
    printf("%d \n", sum(30));

    for (int i = 0; i < 5; ++i) {
        display();
    }
}

static int returnThree() {
    return 3;
}

int sum(int num) {
    static int sum = 0;
    sum += num;
    return sum;
}