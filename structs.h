#pragma once
/*****************************************************************
* Header file to use in your implementation of the project.      *
* Please, do not modify any value or structure that appears here *
*	
//References:							
*****************************************************************/
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct secretKey {
    //secretKey is the secret key contained in the request.
    unsigned int secKey = 123456;
    //newKey (0), fileGet (1), fileDigest (2), fileRun (3).
    unsigned short requestType; 
    unsigned short padding;
};

/*struct host {
    string h_name;		//official name of host 
    int h_addrtype;		//host address type, always AF_INET
	int h_length;		//length of address in bytes
}*/

//Struct Types

