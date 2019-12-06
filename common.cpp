/*****************************************************************
* Header file containing constants for the "library"             *						
*****************************************************************/
extern "C" {
  #include "csapp.h"
}

#include <stdio.h>
using namespace std;

// Const values
const char BUFFER_PADDING[2] = {0x00, 0x00}; // 2 bytes of padding (arbitrary 0's)
const unsigned int MAXDATASIZE = 100;

// Return 0 on success, -1 on failure
int newKey(const char *machineName, unsigned short port, unsigned int secretKey, unsigned int newKey){

}

int fileGet(const char *machineName, unsigned int port, unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength){

}

int fileDigest(char *machineName, unsigned short port, unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength){

}

// Extra Credit
int fileRun(const char *machineName, unsigned short port, unsigned int secretKey, const char *request, char *result, unsigned int *resultLength);
