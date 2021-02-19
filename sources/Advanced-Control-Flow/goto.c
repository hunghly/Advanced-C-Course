#include <stdio.h>

void gotoExample();

int main(void) {
    // a goto function allows you to jump to whereever line you have a label
    // using many gotos ina  program makes it harder to following and maintain
    // often refer to as spaghetti code
    // you should avoid using gotos in your code

    goto label; // jump straight to the goto label

    skipped:
        printf("this gets skipped\n");
        gotoExample();
    return 1;

    label:
        printf("hello world!");

    goto skipped;

}

void gotoExample() {
    int sum = 0;
    int input;
    printf("Enter a number: ");
    while (scanf("%d", &input)) {
        if (input < 0) {
            goto print;
        }
        sum += input;
        printf("Enter a number: ");
    }
    print:
        printf("Your sum is: %d\n", sum);
}