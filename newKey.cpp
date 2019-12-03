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
#include <netdb.h>      //gethostbyname(), struct hostent
#include <iostream>
#include "structs.h"

//#define SERVER "localhost"
//#define PORT "2100"

#define MAXDATASIZE 100 // max number of bytes we can get at once 

using namespace std;

//prints error message, then exits
void error(const char *msg)
{
	perror(msg);
	exit(0);
}


     
 
        
}


int main(int argc, char *argv[]){
    
    unsigned int numArgs = argc;
    if (numArgs != 5){
        error("Incorrect number of arguments\n");
    }
    
    int socketfd;
    int portnum;
    int n;
    //will contain the address of the server to which we want to connect
    struct sockaddr_in server_addr;
    //http://www.linuxhowtos.org/C_C++/socket.htm
    struct hostent *server;
    //returns pointer to hostent constaining information about that host, NULL = couldnt locate host
	server = gethostbyname(argv[1]);
   
    if (server == NULL) {
		fprintf(stderr, "ERROR, no such host\n");
		exit(0);
	}

    unsigned int portNum = atoi(argv[2]);
    unsigned int secKey = atoi(argv[3]);
    unsigned int newSecKey =atoi(argv[4]);
    //This code sets the fields in the  serv_addr struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum); //htons() = host to network byte order
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); 

    //connect() called by client to connect to server 
	//--(socket fd, & of host w/ portnum, sizeof this address)
	//Notice that the client needs to know the port number of the server, 
	//but it does not need to know its own port number.
	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		error("ERROR connecting");
	}


    
    

}
    