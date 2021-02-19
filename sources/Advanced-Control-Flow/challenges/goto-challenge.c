#include <stdio.h>

int main(void) {
    // print a triangle  without using any looping constructs and only goto statements
    /**
     * something like this
     *                                       
     *             *
     *         *        *
     *     *                *
     *    *********************
     */

    goto top;
    bottom:
        printf(" *****************");
        goto stop;
    line4:
        printf("  *             *\n");
        goto bottom;
    line3:
        printf("    *         *\n");
        goto line4;
    line2:
        printf("      *     *\n");
        goto line3;
    top:
        printf("         *   \n");
        goto line2;
    stop:
        return 0;
}