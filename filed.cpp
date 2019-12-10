//
//  main.cpp
//  Server
//
//  Created by Blake Sweet on 10/28/19.
//  Copyright � 2019 Blake Sweet. All rights reserved.

#include <iostream>
#include <csignal>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include "common.cpp"


void printOutput(unsigned int secretKey, short requestType, string detail, int completion) {
	
	cout << "Secret Key = " << secretKey << endl;
	cout << "Request Type = " << requestType << endl;
	cout << "Detail = " << detail << endl;
	cout << "Completion = " << completion << endl;
	cout << "--------------------------" << endl;

}

using namespace std;


int main(int argc, const char * argv[]) {
	while(1){
		// Ex) filed 5678 987654 (5678 = port number, 987654 = secret key) 
		if (argc > 3){
			perror(argv[0]);
			exit(1); // Error
		}
		else if (argc < 3){
			cout << "Correct usage: ./[ServerName] [Port Number] [Secret Key]\n";
			exit(0); // Normal exit type
		}

		int listenfd, connfd, port;
		socklen_t clientlen;
		struct sockaddr_in clientaddr;
		struct hostent *hp;
		char *haddrp;
		unsigned int secKey = 123456;
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
			exit(0)
		}

		listenfd = Open_listenfd(port);
		clientlen = sizeof(clientaddr);

		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);

		/* Determine the domain name and IP address of the client */
		hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
			sizeof(clientaddr.sin_addr.s_addr), AF_INET);
		haddrp = inet_ntoa(clientaddr.sin_addr);

		//printf("server connected to %s (%s)\n", hp->h_name, haddrp);

		unsigned int clientKey;
		//readin key sent from client to verify
		Rio_readn(listenfd, clientKey, sizeof(clientKey));
		//check request type
		
		Rio_readn(listenfd, reqType, sizeof(reqType));
		//ntohl() - to convert from network to host order
		if (clientKey != secKey) {
			int rVal = -1;
			Rio_writen(listenfd, rVal, sizeof(rVal));
			close(listenfd);
			printOutput(secKey, reqType, dataDetail, status);
		}
		//if key is valid, process the rest of client info
		else{
			if (reqType == 0) {
				//read in buffer?
				char BUFFER_PADDING[2];
				Rio_readn(listenfd, BUFFER_PADDING, sizeof(BUFFER_PADDING));
				//read in new secret key
				unsigned int newKeyfromClient;
				Rio_readn(listenfd, newKeyfromClient, sizeof(newKeyfromClient));
				dataDetail = newKeyfromClient;
				printOutput(secKey, reqType, dataDetail, status);
				secKey = newKeyfromClient;
			}
			else if (reqType == 1) {
				//Rio_readn(listenfd, )
			}
		}
	} // While()
	return 0;
} // End of main