/* $begin fileserver.h */
#ifndef __FILESERVER_H__
#define __FILESERVER_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "csapp.h"

//Each of these library routines returns 0 on success and -1 on failure.
//These library routines should build a new connection for each request.
//The connection only lasts for the duration of the single request.

int newKey(const char *machineName, unsigned short port, unsigned int secretKey, unsigned int newKey);

int fileGet(const char *machineName, unsigned int port, unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength);

int fileDigest(char *machineName, unsigned short port, unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength);

int fileRun(const char *machineName, unsigned short port, unsigned int secretKey, const char *request, char *result, unsigned int *resultLength);
#endif /* __FILESERVER_H__ */
/* $end fileserver.h  */