//
//  main.cpp
//  Server
//
//  Created by Blake Sweet on 10/28/19.
//  Copyright © 2019 Blake Sweet. All rights reserved.

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include "common.cpp"

using namespace std;

void PrintOutput(unsigned int secretKey, short requestType, unsigned int recMessageSize, unsigned int clientAddress, unsigned int listenAddress){
	cout << '\n' << "Recieved:" 
   		 	<< "\n\tLength: " << recMessageSize
   			<< "\n\tKey: " << secretKey
   			<< "\n\tClient: " << clientAddress
   		 	<< "\n\tServer: " << listenAddress
   		 	<< "\n\tRequest Type: " << requestType;
}

void DieWithError(string errorMessage){
	perror(errorMessage);
	exit(1);
}

int main(int argc, const char * argv[]) {
	while{
		// Ex) filed 5678 987654 (5678 = port number, 987654 = secret key) 
		if (argc > 3){
			perror(argv[0]);
			exit(1); // Error
		}
		else if (argc < 3){
			cout << "Correct usage: ./[ServerName] [Port Number] [Secret Key]\n";
			exit(0); // Normal exit type
		}

		// Local Variables
		string msgFromClient; // Max size = 102 (Output)
		string msgToClient; // Max size = 108 (Input)
		unsigned int key;
		short type;

		// Read in to msgFromClient


		// Make message back to client
		// msgToClient += ? ;
		// send(msgToClient.c_str()); // Send back as .c_str() for C

	} // while()
} // End of main
