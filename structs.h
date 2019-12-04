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

//requestType = newKey (0), fileGet (1), fileDigest (2), fileRun (3).
struct clientToServer {
    unsigned int secKey;        //4 bytes
    unsigned short requestType; //2 bytes
    unsigned short padding;     //2 bytes
    char details[MAXDATASIZE];  //up to 100 bytes
};


struct ServerToClient {
    int8_t returnCode;          //1 byte 0 or -1
    char pad[3];                //3 bytes
    //below used fileGet, fileDigest, and (extra credit) fileRun response
    unsigned short retValLength; //2bytes
    char returnData[MAXDATASIZE - 6]; //94 bytes, in hex
};