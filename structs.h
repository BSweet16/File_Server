#pragma once
/*****************************************************************
* Header file to use in your implementation of the project.      *
* Please, do not modify any value or structure that appears here *
*	
//References:							
*****************************************************************/
#include <stdio.h>

using namespace std;

struct secretKey {
    //secretKey is the secret key contained in the request.
    unsigned int secKey;   
    //newKey (0), fileGet (1), fileDigest (2), fileRun (3).
    unsigned short requestType; 
    unsigned short padding;
};


//Struct Types

