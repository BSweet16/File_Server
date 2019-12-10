/*****************************************************************
* Header file containing constants for the "library"             *
*****************************************************************/
extern "C" {
	#include "csapp.h"
}

#include <stdio.h>
using namespace std;

// Const values
const char BUFFER_PADDING[2] = { 0x00, 0x00 }; // 2 bytes of padding (arbitrary 0's)
const unsigned int MAXDATASIZE = 100;

// Return 0 on success, -1 on failure
int newKey(const char *machineName, unsigned short port, unsigned int secretKey, unsigned int newKey) {

	int answer = 0; 
	rio_t rio;
	int clientfd;

	//change info to network byte order
	unsigned int secKey = htonl(secretKey);
	unsigned short type = htons(0);
	unsigned int formattedNewKey = htonl(newKey);

	clientfd = Open_clientfd(machineName, port);
	Rio_readinitb(&rio, clientfd);

	//send seckey for validation from server
	Rio_writen(clientfd, secKey, sizeof(secKey);

	//tell server what type of request this is
	Rio_writen(clientfd, type, sizeof(type);

	Rio_readn(clientfd, answer, sizeof(answer));
	if (answer == -1) {
		return answer;
	}
	else {
		Rio_writen(clientfd, BUFFER_PADDING, sizeof(BUFFER_PADDING);
		Rio_writen(clientfd, formattedNewKey, sizeof(formattedNewKey);
		Close(clientfd);
		return answer;
	}
}

int fileGet(const char *machineName, unsigned int port, unsigned int secretKey, 
			const char *fileName, char *result, unsigned int *resultLength) {
	// Usage: /fileGet machineName port secretKey fileName
	// Local Variable
	int responseAnswer = 0; 
	rio_t rio;
	int clientfd;

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

	Rio_readn(clientfd, responseAnswer, sizeof(responseAnswer));
	if (responseAnswer == -1) {
		return responseAnswer;
	}
	else {
		char *fileBuff[MAXDATASIZE];
		if ((ssize_t numFileBytes = read(fileName, fileBuff, MAXDATASIZE)) >= 0){ // If the file exists
			// Transmit first 100 bytes or size of the file back to the client
			Rio_writen(clientfd, &fileBuff, sizeof(fileBuff);
		}
		else{
			perror("Failed to open file");
		}
		close(clientfd);
		return responseAnswer;
	}

}// fileGet

int fileDigest(char *machineName, unsigned short port, unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength) {
	int answer;

	// Code

	return answer;
}

// Extra Credit
int fileRun(const char *machineName, unsigned short port, unsigned int secretKey, const char *request, char *result, unsigned int *resultLength);
