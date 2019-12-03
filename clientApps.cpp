#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h> // sockaddr_in 
#include <netinet/in.h>
#include <netdb.h>      //
#include <iostream>
#include "structs.h"

#define PORT "2100" // the port client will be connecting to 

#define MAXDATASIZE 100 // max number of bytes we can get at once 

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
    if (numArgs != 5)
        error("Incorrect number of arguments, try again.\n");
    
    string machineName = argv[1];
    unsigned int portNum = atoi(argv[2]);
    unsigned int secKey = argv[3];
    
    
    
    if(secKey != secretKey.secKey)
        error("failure\n");

    unsigned int socketFd;
    //create new socket -- (address domain of the socket, socket type, protocol: 0 = TCP)
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
		error("ERROR opening socket");
	}
	//will contain the address of the server to which we want to connect
    struct sockaddr_in server_addr;
    
     server_addr.sin_family = AF_INET;
     server_addr.sin_port = htons(portNum); //htons() = host to network byte order
     server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    
     //client needs to know the port number of the server, 
	 //but it does not need to know its own port number.
     if (connect(socketFd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
	    error("ERROR connecting");
	 }
   



    reqType
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