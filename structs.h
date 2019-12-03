#pragma once
/*****************************************************************
* Header file to use in your implementation of the project.      *
* Please, do not modify any value or structure that appears here *
*	
//References:							
*****************************************************************/
#include <stdio.h>
#include <string>
#include <cstdint> // uint8_t

#define MAXDATASIZE 100
using namespace std;


struct clientToServer {
    //secretKey is the secret key contained in the request.
    unsigned int secKey;
    //newKey (0), fileGet (1), fileDigest (2), fileRun (3).
    unsigned short requestType; 
    //arbitrary values for padding
    unsigned short padding;
};


struct ServerToClient {
    //exactly 8-bit signed int return code: 0 = success, -1 = failure
    int8_t retCode;
    //arbitrary values for padding
    char pad1[3];
    //fileGet, fileDigest, and (extra credit) fileRun response
    unsigned short retValLength;
    //
    char returnData[MAXDATASIZE - 5];
}

