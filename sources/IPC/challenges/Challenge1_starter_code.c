#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>


// write a program that test a user's multiplication skills
// will ask the user to work on an answer to a simple multiplcation program
// keep track of how many answers are correct
// program runs forever until user presses Ctrl-C or takes more than 5 seconds to answer


int score = 0;

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

void handler_interrupt(int signum);

int main() {

   srand (time(0));

   
   while(1) {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];

      void (*sigHandlerReturn)(int);
      sigHandlerReturn = signal(SIGALRM, handler_interrupt);
      alarm(5);
      printf("\nWhat is %d times %d: ", a, b);
      fgets(txt, 4, stdin);

      int answer = atoi(txt);

      if(answer == a * b)
         score++;
      else
         printf("\nWrong! Score: %d\n", score);
    }

    return 0;
} 

void handler_interrupt(int signum) {
   if (signum == SIGINT) {
      printf("\n Interrupt detected...Ending game.\n");
      end_game();
   }
   else if (signum == SIGALRM) {
      printf("Waited too long.\n");
      end_game();
   }
}
