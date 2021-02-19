#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery() {
    longjmp(buf, 101);
}

int main(void) {
    /**
     * use setjmp and longjmp to gracefully handle unrecoverable program errors
     * -when error is encountered - transfer control back to the main input loop and start again from there
     * -create function called error_recovery - that prints out an error and then use longjmp to transfer
     * control back to a main function loop
     * -your main function should include a forever loop that uses setjmp at the top of the loop before proccessing
     * -you can add "dummy" code in your loop that simulates an error(by calling error_recover) when
     * setjmp returns 0
     *
     */
    // int i;
    // printf("Please enter a value for i. i > 100 exits program.\n");
    // scanf("%d", &i);
    int i = setjmp(buf); // sets the jump buffer
    printf("jmp_buf=%d\n", i);
    while (i < 100) {
        // this will run forever
        error_recovery();
    }

}