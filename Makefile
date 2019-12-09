
csapp.o: csapp.h csapp.c

$(SERVER): csapp.o
$(CLIENTS): csapp.o common.o

.PHONY: clean
clean:
	/bin/rm -rf csapp.h csapp.c *.o filed newKey fileGet fileDigest fileRun

zip:
	zip project5.zip *.c README

