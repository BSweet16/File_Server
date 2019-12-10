CC = -g++
CFLAGS = -Wall
LDLIBS = -lpthread

SERVER = filed
CLIENTS = newKey
CSAPP = csapp.h csapp.c
DEPS = common.h

all: $(CSAPP) $(SERVER) $(CLIENTS)

csapp.h:
	wget http://csapp.cs.cmu.edu/2e/ics2/code/include/csapp.h

csapp.c:
	wget http://csapp.cs.cmu.edu/2e/ics2/code/src/csapp.c

csapp.o: csapp.h csapp.c

$(SERVER): csapp.o filed.o
$(CLIENTS): csapp.o newKey.o
$(DEPS): commmon.h

.PHONY: clean
clean:
	/bin/rm -rf csapp.h csapp.c *.o filed newKey common

zip:
	zip project5.zip *.c README