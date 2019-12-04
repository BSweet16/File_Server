//#pragma once
/*****************************************************************
* Header file to use in your implementation of the project.      *
* Please, do not modify any value or structure that appears here *
*	
//References:							
*****************************************************************/
#include <stdio.h>
//#include <string>
#include <cstdint> // int8_t

#define MAXDATASIZE 100
using namespace std;


struct clientToServer {
    //secret key contained in the request.
    unsigned int secKey;
    //newKey (0), fileGet (1), fileDigest (2), fileRun (3).
    unsigned short requestType; 
    //arbitrary values for padding
    unsigned short padding;
    //for sending newkey or filepath
    char details[MAXDATASIZE];
};


struct ServerToClient {
    //exactly 8-bit(1 byte) signed int return code: 0 = success, -1 = failure
    int8_t returnCode;
    //arbitrary values for padding
    char pad[3];
    //fileGet, fileDigest, and (extra credit) fileRun response
    unsigned short returnValLength;
    //max size for return data, display in hex
    char returnData[MAXDATASIZE - 5];
};
