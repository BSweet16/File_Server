//#pragma once
/*****************************************************************
* Header file containing constants for the "library"             *
*****************************************************************/
// common.h
#ifndef COMMON_H // include guard
#define COMMON_H

extern "C" {
#include "csapp.h"
}
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/in.h>
using namespace std;

// Const values

const unsigned int MAXDATASIZE = 100;

// Return 0 on success, -1 on failure
int newKey(char *machineName, unsigned short port, unsigned int secretKey, unsigned int newerKey) {

	int answer = 0;
	//rio_t rio;
	//char buf[MAXLINE];
	int clientfd;
	char BUFFER_PADDING[2] = { 0x00, 0x00 }; // 2 bytes of padding (arbitrary 0's)

	//change info to network byte order
	unsigned int secKey = htons(secretKey);
	unsigned short type = htons(0);
	unsigned int formattedNewKey = htonl(newerKey);
	printf("machine name: %s,  port: %d\n", machineName, port);
	clientfd = Open_clientfd(machineName, port);

	Rio_writen(clientfd, &secKey, sizeof(secKey));

	Close(clientfd);

	//send secKey for validation from server
	//Rio_writen(clientfd, &secKey, sizeof(secKey));
	//Close(clientfd);
	//tell server what type of request this is
/*	Rio_writen(clientfd, &type, sizeof(type));

	Rio_readn(clientfd, &answer, sizeof(answer));
	if (answer == -1) {
		return answer;
	}
	else {
		Rio_writen(clientfd, BUFFER_PADDING, sizeof(BUFFER_PADDING));
		Rio_writen(clientfd, &formattedNewKey, sizeof(formattedNewKey));
		Close(clientfd);
		return answer;
	}
}
*/
}
/*int fileGet(const char *machineName, unsigned int port, unsigned int secretKey,
	const char *fileName, char *result, unsigned int *resultLength) {
	// Usage: /fileGet machineName port secretKey fileName
	// Local Variable
	int responseAnswer = 0;
	rio_t rio;
	int clientfd;
	char *fileBuff[MAXDATASIZE];

	//change info to network byte order
	unsigned int secKey = htonl(secretKey);
	unsigned short type = htons(0);
	unsigned int recievedFileName = htonl(newKey);

	clientfd = Open_clientfd(machineName, port);
	Rio_readinitb(&rio, clientfd);

	//send seckey for validation from server
	Rio_writen(clientfd, secKey, sizeof(secKey);

	//tell server what type of request this is
	Rio_writen(clientfd, type, sizeof(type);

	while (1) {
		// Transmit first 100 bytes or size of the file back to the client
		size_t numReadBytes = Rio_readn(clientfd, fileBuff, MAXDATASIZE);

		if (numReadBytes == 0) { // End of the file
			Rio_writen(clientfd, &fileBuff, sizeof(fileBuff));
			break;
		}
		else { // Read as many bytes as you have
			Rio_writen(clientfd, fileBuff, numReadBytes);
			Rio_writen(1, "\n", 1);
			fileBuff += numReadBytes;
		}
	}


	Close(clientfd);
	return 0; // Success

}// fileGet
*/
/*int fileDigest(char *machineName, unsigned short port, unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength) {
	int answer;

	// Code

	return answer;
}*/

// Extra Credit
//int fileRun(const char *machineName, unsigned short port, unsigned int secretKey, const char *request, char *result, unsigned int *resultLength);


#endif /* COMMON_H */