#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

// creates the socket
short socketCreate(void) {
    short hSocket;
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    printf("Created the socket %d\n", hSocket);
    return hSocket;
}

// binds the socket
int bindCreatedSocket(int hSocket) {
    int iRetval = -1;
    int clientPort = 12345; // initializes the client port

    struct sockaddr_in remote = { 0 }; // initializes the sockaddr_in struct to all zeros

    // internet address family
    remote.sin_family = AF_INET; // sets the internet protocol to IPv4
    printf("Your sin_family %d\n", remote.sin_family);
    // any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY); // converts host to network as a long
    printf("Your s_addr %u\n", remote.sin_addr.s_addr);
    remote.sin_port = htons(clientPort); // local port, convert host to network as a short
    printf("Your sin_port %d\n", remote.sin_port);

    iRetval = bind(hSocket, (struct sockaddr*) &remote, sizeof(remote)); // binds the socket
    return iRetval;
}


int main(void) {
    // short socketfd;
    // socketfd = socketCreate();
    // bindCreatedSocket((int) socketfd);


    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "hello from server";

    // create the socket
    socket_desc = socketCreate();
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket created\n");

    // bind the socket
    if (bindCreatedSocket(socket_desc) == -1) {
        printf("Unable to bind socket\n");
        return 1;
    }
    printf("Socket binded\n");

    // listen to the socket
    listen(socket_desc, 3); // creates a listener that listens up to 3 connections

    // accept any incoming connections. this runs forever, waiting for connections
    while (1) {
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);
        
        // accept connection from incoming client and assign it to sock (client)
        sock = accept(socket_desc, (struct sockaddr*) &client, (socklen_t*) &clientLen);

        // check if the socket was accepted or failed
        if (sock < 0) {
            perror("accept failed");
            return 1;
        }
        printf("Connection accepted\n");
        memset(client_message, '\0', sizeof(client_message)); // essentially this zeros out the client message
        memset(message, '\0', sizeof(message)); // essentially this zeros out the message
        // printf("client message is %s\n", client_message);

        // try to recv the message
        if (recv(sock,client_message, 200, 0) < 0) {
            printf("recv failed");
            break;
        }
        printf("Client reply: %s\n", client_message);

        // if we compare the client message to our secret message, then we can send a message back
        if (strcmp(pMessage, client_message) == 0) {
            strcpy(message, "Hi there!");
        } else {
            strcpy(message, "invalid mesage!");
        }

        // send some data
        if (send(sock, message, strlen(message), 0) < 0) {
            printf("send failed\n");
            return 1;
        }

        close(sock);
        sleep(1);
    }


    return 0;
}