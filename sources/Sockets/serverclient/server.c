#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

short socketCreate(void) {
    short hSocket;
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    printf("Created the socket %d\n", hSocket);
    return hSocket;
}

int bindCreatedSocket(int hSocket) {
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = { 0 };
}


int main(void) {
    socketCreate();
    return 0;
}