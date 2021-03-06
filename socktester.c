#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

main(int argc, char **argv){
	int status;
	struct addrinfo hints;
	struct addrinfo *res, *p;
	char ipstr[INET6_ADDRSTRLEN];
	
	if(argc!=2) {
		fprintf(stderr, "LENServ: Undefined Usage!\n");
		return 1;
		}
	memset(&hints, 0, sizeof(hints));
	
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
		fprintf(stderr, "LENServ: getaddrinfo: %s\n", gai_strerror(status));
		return 2;
		}
	printf("\n\tWelcome To LenServ!\n\tYour own Linux Socket Streamer!\n\tIP addresses for %s:\n\n", argv[1]);
	for(p = res;p != NULL; p = p->ai_next) {
			void *addr;
			char *ipver;
// get the pointer to the address itself,
// different fields in IPv4 and IPv6:
		if (p->ai_family == AF_INET) { // IPv4
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		} else { // IPv6
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}
// convert the IP to a string and print it:
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
		printf(" %s: %s\n", ipver, ipstr);
		}
freeaddrinfo(res); // free the linked list
return 0;
}

