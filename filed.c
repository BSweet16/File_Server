/* $begin filed.c */
//Authors: Joe Hall and Blake Sweet

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "csapp.h"

//max size of DNS name, i.e. george.netlab.uky.edu or 128.163.146.12
const int machineNameSize = 40;
//the number to use as the secretKey when communicating with your server
const char secretKey[8] = "0162";



int main(int argc, char **argv)
{
	int listenfd, connfd, port;
	socklen_t clientlen;
	struct sockaddr_in clientaddr;
	struct hostent *hp;
	char *haddrp;
	if (argc == 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[1]);
		//exit(0)
		if (argv[2] == secretKey) {
			port = atoi(argv[1]);
			listenfd = open_listenfd(port);
		}
		else
			exit(0);
	}
	
	while (1) {
		clientlen = sizeof(clientaddr);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);

		/* Determine the domain name and IP address of the client */
		hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
			sizeof(clientaddr.sin_addr.s_addr), AF_INET);
		haddrp = inet_ntoa(clientaddr.sin_addr);
		printf("server connected to %s (%s)\n", hp->h_name, haddrp);
		printf("%d", connfd);
		
		Close(connfd);
	}
	exit(0);
}
/* $end filed.c */