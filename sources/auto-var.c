#include <stdio.h>

int main() {
    auto int x; // local var same as int x;
    { // adding in another scope
        int i = 30;
        printf("%d inside braces", i);
    }
    // printf("%d outside braces", i); // will cause an error
    return 0;
}

int func_name() {
    int y; // local var
    return y;
}