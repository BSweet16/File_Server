//
//  main.cpp
//  Server
//
//  Created by Blake Sweet on 10/28/19.
//  Copyright © 2019 Blake Sweet. All rights reserved.

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include "structs.h"
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
	// Ex) filed 5678 987654 (5678 = port number, 987654 = secret key) 
	// if (argc != 3){
	// 	perror(argv[0]);
	// 	exit(1);
	// }

	// Local variables
	char buff[MAXDATASIZE+8]; // = Data + secretKey
	unsigned int listenAddress;
	unsigned int clientAddress;
	unsigned int port; //= argv[2]

	unsigned int secretKey; //= argv[3] // Like a PIN
	short requestType;
	unsigned int counter = 0;
	unsigned int cliAddrLen; // Length of incoming message
	unsigned int recMessageSize; // Size of recieved message (bytes)

	// Listen for information
	while (counter < MAXDATASIZE){
		//buff[counter];// = recieved data;

		// Create socket for sending/recieving
		if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
			DieWithError("socket() failed");
		}

		/* ==========================
    	*	Construct local address structure
    	   ========================== */
   		memset(&echoServAddr, 0, sizeof(echoServAddr));   // Zero out structure
    	echoServAddr.sin_family = AF_INET;                // Internet address family
    	echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface
    	echoServAddr.sin_port = htons(echoServPort);      // Local port

    	/* ==========================
    	*	Bind to the local address
    	   ========================== */ 
		// Test for errors
	    if (bind(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0){
	        DieWithError("bind() failed");
	    } 
	    cliAddrLen = sizeof(clientAddress);
	    if ((recMessageSize = recvfrom(sock, echoBuffer, MAXDATASIZE, 0, &clientAddress, &cliAddrLen)) < 0){
	    	DieWithError("recvfrom() failed");
	    }       

	    // Mark the end of the message
	    cout << "Handling client " << inet_ntoa(clientAddress) << '\n';
	    buff[recMessageSize] = '\0';
	    cout << "Recieved: " << buff << '\n';

	    // Define variables for recieving information
	    recMessageSize = sizeof(buff);

	    // Recieve message
	    if ((recvMsgSize = recvfrom(listenAddress, &buff, recMessageSize, 0, &clientAddress, &cliAddrLen)) < 0){
	    	DieWithError("recvfrom() failed");
	    }

	   	// Output
		PrintOutput(secretKey, requestType, recMessageSize, clientAddress, listenAddress);

		counter++;
	}
}
