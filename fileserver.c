/* $begin fileserver.c */
#include "csapp.h"

//newkey() - Bytes 8-11: the new secret key, as an unsigned 32-bit int, in network byte order.
int newKey(const char *machineName, unsigned short port, unsigned int secretKey, unsigned int newKey) {

}

//fileGet() -Bytes 8-107: a null-terminated file name, no longer than 100 characters.
int fileGet(const char *machineName, unsigned int port, unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength) {

}

//fileDigest() - Bytes 8-107: a null-terminated file name, no longer than 100 characters.
int fileDigest(char *machineName, unsigned short port, unsigned int secretKey, const char *fileName, char *result, unsigned int *resultLength) {

}

//fileRun() - Byte 8-23: a 16-byte string (null terminated) holding one of the valid values.
int fileRun(const char *machineName, unsigned short port, unsigned int secretKey, const char *request, char *result, unsigned int *resultLength) {

}
/* $end fileserver.c */