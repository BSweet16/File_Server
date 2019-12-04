//
//  main.cpp
//  Server
//
//  Created by Blake Sweet on 10/28/19.
//  Copyright © 2019 Blake Sweet. All rights reserved.

#include <iostream>
#include "struct.h"
using namespace std;

void printOutput(unsigned int secretKey, short requestType){
	cout << "Secret key: " << secretKey << '\n'
		 << "Request Type: " << requestType << '\n';
}

int main(int argc, const char * argv[]) {
	// Local variables
	unsigned int secretKey;
	short requestType;
	const char BUFFER_PADDING[2] = {0x00, 0x00}; // 2 bytes of padding (arbitrary 0's)

	// Keep in loop
		//undo network byte order
			// store as secret key

		// Test for correct number of arguments
		// Create socket for sending and recieving data (Structs)
		// Construct local address structure
		// Bind to local address
			// Interpret data
			// Print data
			printOutput(secretKey, requestType);
}
