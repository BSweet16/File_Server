#include "common.cpp"
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
#include <arpa/inet.h> //inet_pton

extern "C" {
#include "csapp.h"
}

//#define SERVER "localhost"
//#define PORT "2100"
#define MAXDATASIZE 107

using namespace std;

int main(int argc, char *argv[])
{

	unsigned int numArgs = argc;
	if (numArgs != 5)
	{
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		exit(0);
	}

	char *machName = argv[1];
	unsigned short portNum = atoi(argv[2]);
	unsigned int secKey = atoi(argv[3]);
	unsigned int newKey = atoi(argv[4]);	

	int retVal = newKey(machName, portNum, secKey, newKey);
	
	if (retVal == -1) {
		cout << "failure." << endl;
	}
	else
		cout << "success." << endl;
	return 0;
}
