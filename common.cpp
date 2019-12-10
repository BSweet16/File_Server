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
const unsigned int SUCCESS = 0;
const int FAILURE = -1;

void RedirectStandardStreamsToTemp(int *_piOriginalSTDIN_FILENO, int *_piOriginalSTDOUT_FILENO, int *_piOriginalSTDERR_FILENO){
        fflush(stdout);
        fflush(stderr);

        *_piOriginalSTDIN_FILENO = dup(STDIN_FILENO);
        *_piOriginalSTDOUT_FILENO = dup(STDOUT_FILENO);
        *_piOriginalSTDERR_FILENO = dup(STDERR_FILENO);

        int devnull = open(TMP_PATH.c_str(), O_RDWR);
        dup2(devnull, STDIN_FILENO);
        dup2(devnull, STDOUT_FILENO);
        dup2(devnull, STDERR_FILENO);
        close(devnull);
}

// Return 0 on success, -1 on failure
int newKey(const char *machineName, unsigned short port, unsigned int secretKey, unsigned int newKey) {

	int answer = SUCCESS; 
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

	while(1){
		// Transmit first 100 bytes or size of the file back to the client
		size_t numReadBytes = Rio_readn(clientfd, result, MAXDATASIZE);

		if (numReadBytes == FAILURE){ // Error finding file
			cout << "File does not exist or is not accessible\n";
			return FAILURE;
		}
		
		if (numReadBytes == 0) { // End of the file
			Rio_writen(clientfd, &result, sizeof(result));
			break; // Exit while()
		}
		else { // Read as many bytes as you have, and move index
			Rio_writen(clientfd, result, numReadBytes);
			Rio_writen(1, "\n", 1);
			result += numReadBytes;
		}
	}

	Close(clientfd);
	return SUCCESS; // Success

}// fileGet

int fileDigest(char *machineName, unsigned short port, unsigned int secretKey, 
			   const char *fileName, char *result, unsigned int *resultLength) {
	// Usage: /fileDigest machineName port secretKey fileName
	// Local Variable
	int returnValue;
	rio_t rio;
	int clientfd;
	//??? content;

	// Change info to network byte order
	unsigned int secKey = htonl(secretKey);
	unsigned short type = htons(0);
	unsigned int recievedFileName = htonl(newKey);

	clientfd = Open_clientfd(machineName, port);
	Rio_readinitb(&rio, clientfd);

	// Send seckey for validation from server
	Rio_writen(clientfd, secKey, sizeof(secKey);
		
	// Tell server what type of request this is
	Rio_writen(clientfd, type, sizeof(type);

	// Read in file to generate a cryptographic digest of
	size_t numReadBytes = Rio_readn(clientfd, result, MAXDATASIZE);

	// Exec SHA256
    pid_t pid = fork();
    // if (pid == 0){ // I am the child
    //     RedirectStandardStreamsToTemp(&iOriginalSTDIN_FILENO, &iOriginalSTDOUT_FILENO, &iOriginalSTDERR_FILENO); // Redirect standard output to a tmp file
    //     returnValue = execvp("/usr/bin/sha256sum", fileName.c_str()); // Exec a process to execute the command
    //     if (returnValue < 0){ // Returned with error
    //         perror("run error");
    //     }
    // }
    // else{ // I am the parent
    //     waitpid(pid, 0, 0);
        
    //     // Read the temp file created into tmp buffer
    //     ifstream tempFile("/usr/bin/temp/tempOut.txt"); // Taking file as inputstream
    //     string content = "";
    //     if(tempFile) {
    //        ostringstream ss;
    //        ss << tempFile.rdbuf(); // Reading data
    //        content = ss.str();
    //     }
    // }

	return content;
}

// Extra Credit
int fileRun(const char *machineName, unsigned short port, unsigned int secretKey, const char *request, char *result, unsigned int *resultLength);
