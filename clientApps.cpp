#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include structs.h

using namespace std;

#define BUFLEN 256
#define MAX_ARGS 30

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
    string machName;
    unsigned short prt;
    unsigned int secKey;
    unsigned int newSecKey;



    //char *fd;
    //char *resultt;
    //unsigned int *resultLen;
    if(argv[0].length

    }

}
// ./newKey $host $port $key $newKey
int newKey(const char *machineName, unsigned short port,
 unsigned int secretKey, unsigned int newKey){

 }

//int fileGet(const char *machineName, unsigned int port,
// unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength);

//int fileDigest(char *machineName, unsigned short port,
// unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength);

//int fileRun(const char *machineName, unsigned short port,
// unsigned int secretKey, const char *request, char *result, unsigned int *resultLength);