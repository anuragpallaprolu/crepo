#include <stdio.h> //Standard input output
#include <sys/types.h>//libsys for datatypes, avoids long and <<
#include <netdb.h>//netdb lib for AF_ based commands
#include <stdlib.h>//memset, malloc et al
#include <string.h>//memset parent lib

/*
int getaddrinfo(const char *node, 
		const char *service, 
		const struct addrinfo *main/hints, 
		struct **addrinfo servinfo/resultserv);
*/

main(){
	int status; //status of connection
	struct addrinfo hints;//a standard ADDRINFO struct for a socket
	struct addrinfo *servinfo;//the linked list to recieve server info
	
	memset(&hints, 0, sizeof(hints));//clear the struct
	
	hints.ai_family = AF_UNSPEC;//eithe AF_INET, OR AF_INET6/IPv6
	hints.ai_socktype = SOCK_STREAM;//Stream sockets not dgram
	hints.ai_flags = AI_PASSIVE;//fill in rest
	if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {//if connection has failed and returned with non zero status.
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
	//	exit(1);
		}
	else printf("\nlYNCH Netserv Activated! Great Success!\n\n");
	freeaddrinfo(servinfo);//free the list, again a standard function from netdb.h
}
