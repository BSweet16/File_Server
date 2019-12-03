#include "structs.h"
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> //defines the sockaddr_in struct
#include <netdb.h>      //gethostbyname(), struct hostent
#include <iostream>

//#define SERVER "localhost"
//#define PORT "2100"
#define MAXDATASIZE 107

using namespace std;

//prints error message, then exits
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{

    unsigned int numArgs = argc;
    if (numArgs != 5)
    {
        error("failure\n");
    }

    int socketfd;
    int retVal;
    //will contain the address of the server to which we want to connect
    struct sockaddr_in server_addr;
    //information to send to
    struct clientToServer cS;
    //http://www.linuxhowtos.org/C_C++/socket.htm
    //struct hostent *server;
    //returns pointer to hostent constaining information about that host, NULL = couldnt locate host
    //server = gethostbyname(argv[1]);

    string hostName = argv[1]; //should this be defined or is it dynamic, how is this tested?
    unsigned short portNum = atoi(argv[2]);

    //load up struct from cmd arguments
    cS.secKey = atoi(argv[3]);
    //request type is 0 for changing secret key
    cS.requestType = ntohs(0);
    //arbitary numbers for padding
    cS.padding = ntohs(11);
    cS.details = atoi(argv[4]);
   

    //creating socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (socketfd == -1)
    {
        error("failure\n");
    }
    //clear out server_addr
    bzero(&server_addr, sizeof(server_addr)); 

    //This code sets the fields in the  serv_addr struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);         //htons() = host to network byte order
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //not sure what to put here, this may be correct


    //connect() called by client to connect to server
    //--(socket fd, & of host w/ portnum, sizeof this address)
    //Notice that the client needs to know the port number of the server,
    //but it does not need to know its own port number.
    if (connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error("failure\n");
    }
    
    char buffer[MAXDATASIZE];
    //concatonate struct values for transmission
    sprintf(buffer, "%d%d%d%d", cS.secKey, cS.requestType, cS.padding, cS.details); 

    n = write(socketfd, buffer, strlen(buffer));
    if (n < 0){
		error("ERROR writing to socket");
    }

	bzero(buffer, 256);
    close(socketfd);
	return 0;

}
