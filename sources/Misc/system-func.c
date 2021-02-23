// the system function passes the command name or program name specified as an argument to the host environment
// to be executed by the command processor and returns after the command has been completed
// allows you to execute programs ont he console/shell
// int system( const char *command );
// returns -1 on error, and the return status of the command otherwise
#include <stdlib.h>

int main(void) {

    system("echo 'hello world'"); // echos hello world
    system("ls -l"); // lists dir files
    system("pwd");
    return 0;
}