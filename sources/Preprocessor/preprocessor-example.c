#include <stdio.h>

#define COMMAND(NAME) {#NAME, NAME##_command}

// a c program that interprets named commands
struct command {
    char *name;
    void (*function)(void);
};

#define MAKESTR(STR, type) #STR #STR #STR #type

int main() {
    // struct command commands[] = {
    //     // {"quit", quit_command},
    //     // {"help", help_command},
    //     COMMAND(quit), // using a macro can remove the unecessary need to type out each individual command
    //     COMMAND(help),
    // };
    puts(MAKESTR(hello world!, int));
    return 0;
}