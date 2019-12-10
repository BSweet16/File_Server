
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "common.cpp"

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
