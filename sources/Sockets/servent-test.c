#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

//struct servent *getservbyname(const char *name, const char *proto);
// struct servent *getservbyport(int port, const char *proto);
int main(void) {
    
    // struct servent {
	// char	*s_name;	/* official service name */
	// char	**s_aliases;	/* alias list */
	// int	s_port;		/* port # */
	// char	*s_proto;	/* protocol to use */
    //  }
    
    struct servent *myservice;
    myservice = getservbyname("echo", "tcp");

    printf("my service name is %s at port %d\n", myservice->s_name, myservice->s_port);
    return 0;
}