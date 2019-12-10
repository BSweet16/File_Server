
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "common.h"

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
	unsigned int newerKey = atoi(argv[4]);	
	int retVal;
	retVal = newKey(machName, portNum, secKey, newerKey);
	if (retVal == -1) {
		cout << "failure." << endl;
	}
	else
		cout << "success." << endl;
	return 0;
}