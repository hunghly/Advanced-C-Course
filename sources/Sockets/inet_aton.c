#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

/*
in_addr_t inet_addr(const char *cp);

in_addr_t inet_lnaof(struct in_addr in);

struct in_addr inet_makeaddr(in_addr_t net, in_addr_t lna);

in_addr_t inet_netof(struct in_addr in);

in_addr_t inet_network(const char *cp);

char *inet_ntoa(struct in_addr in);
*/

int main() {
    char* ipaddr = "192.168.1.1";
    in_addr_t inaddt;

    inaddt = inet_addr(ipaddr);

    printf("what is inaddt? %d\n", inaddt);
    return 0;
}