#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void myFunction() {
    printf("in my function()\n");
    longjmp(buf, 1);

    // Code after this will not be reached
    printf("You won't see this code\n");
}

int main(void) {

    // mainly used to implement exception handling in C (error recovery situations)
    // setjmp can be used like try (in languages like C++ and Java)
    // longjmp can be used like throw

    // setjmp saves a copy of the program counter and the current pointer to the top of the stack
    /**
     * int setjmp(jmp_buf j)
     *  -use the variable j to remember where you are now
     *  -must be called first before longjmp
     * 
     * int longjmp(jmp_buf , int i)
     *  -tells code to go back to the place that j is set to and restores the process in the state that existed
     * when setjmp was called
     *  -the contents of j is destroyed in the process of using longjmp
     * 
     * called unwinding the stack because you unroll the activation records from the stack until you get to the
     * saved one
     * 
     * a goto can't jump out of current function in C but longjump can
     */



    // int i = setjmp(buf);
    // printf("i=%d\n", i); // print out the buf

    // if (i != 0) {
    //     exit(0); // do this conditional to exit the indefinite loop 
    // }

    // longjmp(buf, 100); // jump back to setjmp and assign the return value as 100

    if (setjmp(buf)) {
        printf("back in main\n");
    } else {
        printf("first time through\n");
        myFunction();
    }

    /**
     * You can have a switch statement to handle errors i.e.
     * switch (setjmp(jbuf)) {
     *  case 0:
     *      apple = *suspicious;
     *      break;
     *  case 1:
     *      printf("bad pointer");
     *      break;
     *  default:
     *      die("unexpected return value by setjmp")
     * }
     */
    return 0;
}