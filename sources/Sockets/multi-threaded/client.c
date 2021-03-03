#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
create client sockets with socket() call
connect to socket using connect()
send/recv data
*/

short socketCreate(void) {
    short hSocket;
    printf("Creating socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int socketConnect(int hSocket) {
    int retVal = -1;
    int serverPort = 12345;
    struct sockaddr_in remote = {0}; // initialize to zero
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); // tells it to run the connection to local host (typically it would be on another ip)
    remote.sin_family = AF_INET;
    remote.sin_port = htons(serverPort); // converts the server port to a type in_port_t and sets it in the struct
    retVal = connect(hSocket, (struct sockaddr*) &remote, sizeof(struct sockaddr_in));
    printf("Socket here %d\n", retVal);
    return retVal;
}

int socketSend(int hSocket, char* rqst, short lenRqst) {
    int shortRetVal=-1;
    // timeval = options for socket
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof(tv)) < 0) {
        printf("Time out\n");
        return -1;
    }
    shortRetVal = send(hSocket, rqst, lenRqst, 0); // send data
    return shortRetVal;
}

int socketReceive(int hSocket, char* rsp, short rvcSize) {
    int shortRetval = -1;
    struct timeval tv;
    // sets the timeval
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv, sizeof(tv)) < 0) {
        printf("Timeout in receive\n");
        return -1;
    }
    shortRetval = recv(hSocket, rsp, rvcSize, 0); // receive and store into rsp
    // printf("Response: %s\n", rsp);
    return shortRetval;
}

int main(void) {

    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = {0};
    char server_reply[200] = {0};

    // create socket
    hSocket  = socketCreate();

    if (hSocket == -1) {
        printf("Could not create socket\n");
        exit(1);
    }

    printf("Socket created!\n");
    if ((socketConnect(hSocket)) < 0 ) {
        printf("Connect failed\n");
        exit(1);
    }
    printf("Socket connected\n");
    // printf("Enter the message: ");
    // fgets(sendToServer, 100, stdin);

    // // send information to server
    // socketSend(hSocket, sendToServer, strlen(sendToServer));
    
    // //receive data from server
    // read_size = socketReceive(hSocket, server_reply, 200);
    // printf("Server responded with %s\n\n", server_reply);

    while (1) {
        printf("Enter the message: ");
        fgets(sendToServer, 100, stdin);
        // send information to server
        socketSend(hSocket, sendToServer, strlen(sendToServer));
        
        //receive data from server
        read_size = socketReceive(hSocket, server_reply, 200);
        printf("Server responded with %s\n\n", server_reply);
        if (strcmp(server_reply, "shutdown") == 0) {
            printf("shutting down\n");
        }
        sleep(3);
    }

    close(hSocket);

    return 0;
}