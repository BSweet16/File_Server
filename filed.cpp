//
//  main.cpp
//  Server
//
//  Created by Blake Sweet on 10/28/19.
//  Copyright © 2019 Blake Sweet. All rights reserved.
#include <iostream>
#include <csignal>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include "common.h"
#include <arpa/inet.h> // for network byte reorder
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>  //contains definitions of a number of data types used in system calls
#include <sys/socket.h> //includes a number of definitions of structures needed for sockets.
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses. (INADDR_ANY)
#include "csapp.h"

void printOutput(unsigned int secretKey, unsigned short requestType,
	string detail, int completion) {
	cout << "Secret Key = " << secretKey << endl;
	cout << "Request Type = " << requestType << endl;
	cout << "Detail = " << detail << endl;
	cout << "Completion = " << completion << endl;
	cout << "--------------------------" << endl;
}

using namespace std;

int main(int argc, const char * argv[]) {
	int listenfd, port, readSocket;
	socklen_t clientlen; //This is needed for the accept system call.
	struct sockaddr_in clientaddr;
	struct hostent *hp;
	char *haddrp;
	unsigned int clientKey;


	unsigned int secKey = 123456;
	unsigned int testKey;
	string dataDetail;
	int status = 0;
	unsigned short reqType;

	if (argc > 3) {
		perror(argv[0]);
		exit(1); // Error
	}
	else if (argc < 3) {
		cout << "Correct usage: ./[ServerName] [Port Number] [Secret Key]\n";
		exit(0); // Normal exit type
	}

	port = atoi(argv[1]);
	testKey = atoi(argv[2]);

	if (testKey != secKey) {
		cout << "Incorrect Key." << endl;
		exit(0);
	}

	listenfd = Open_listenfd(port);

	clientlen = sizeof(clientaddr);
	readSocket = Accept(listenfd, (SA *)&clientaddr, &clientlen);

	/* Determine the domain name and IP address of the client */
	hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
		sizeof(clientaddr.sin_addr.s_addr), AF_INET);
	haddrp = inet_ntoa(clientaddr.sin_addr);

	printf("server connected to %s (%s)\n", hp->h_name, haddrp);
	if (readSocket == -1) {
		printf("error with accepting socket");
	}
	else {
		while (1) {
			Rio_readn(readSocket, &clientKey, sizeof(clientKey));

			printf("client Key is: %d \n", clientKey);
		}
		Close(listenfd);
	}

	/*
Rio_readn(listenfd, &reqType, sizeof(reqType));
//ntohl() - to convert from network to host order
if (clientKey != secKey) {
	int rVal = -1;
	Rio_writen(listenfd, &rVal, sizeof(rVal));
	close(listenfd);
	printOutput(secKey, reqType, dataDetail, status);
}
//if key is valid, process the rest of client info
else{
	//0 for newKey
	if (reqType == 0) {
		//read in buffer?
		char BUFFER_PAD[2];
		Rio_readn(listenfd, BUFFER_PAD, sizeof(BUFFER_PAD));
		//read in new secret key
		unsigned int newKeyfromClient;
		Rio_readn(listenfd, &newKeyfromClient, sizeof(newKeyfromClient));
		dataDetail = newKeyfromClient;
		printOutput(secKey, reqType, dataDetail, status);
		secKey = newKeyfromClient;
	}
	else if (reqType == 1) {
		//Rio_readn(listenfd, )
	}

*/
//exit(0);

} // End of main