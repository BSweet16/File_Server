#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "structs.h"

using namespace std;

//Each of these library routines returns 0 on success and -1 on failure.
//These library routines should build a new connection for each request.
//The connection only lasts for the duration of the single request.


void error(const char *msg)
{
	perror(msg);
	exit(0);
}

int newKey(const char *machineName, unsigned short port,
 unsigned int secretKey, unsigned int newKey);

//int fileGet(const char *machineName, unsigned int port,
// unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength);

//int fileDigest(char *machineName, unsigned short port,
// unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength);

//int fileRun(const char *machineName, unsigned short port,
// unsigned int secretKey, const char *request, char *result, unsigned int *resultLength);

int main(int argc, char *argv[]){
    
    unsigned int numArgs = argc;
    if (numArgs != 4)
        error("Incorrect number of arguments, try again.\n");
    
    string machineName = argv[1];
    unsigned portNum = atoi(argv[2]);
    unsigned int secKey = argv[3];

    
    //unsigned int newSecKey

    string request;
    unsigned socketFd;
    //create new socket -- (address domain of the socket, socket type, protocol: 0 = TCP)
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
		error("ERROR opening socket");
	}
	
    //stores return value for the read() and write() calls
	unsigned int retVal;
    string request;
    //will contain the address of the server to which we want to connect
	struct sockaddr_in serv_addr;


    if(secKey != secretKey.secKey)
        error("Wrong security key entered, try again.");

        if(newKey() < 1) 
            cout << "failure\n";
        else   
            cout << "success\n";
        
        



}

// ./newKey $host $port $key $newKey
int newKey(unsigned int newKey){
    secretKey.seckey = newKey;
 }

//int fileGet(const char *machineName, unsigned int port,
// unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength);

//int fileDigest(char *machineName, unsigned short port,
// unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength);

//int fileRun(const char *machineName, unsigned short port,
// unsigned int secretKey, const char *request, char *result, unsigned int *resultLength);