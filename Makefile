# Makefile for Project 5 of CS270, Fall 2019.

PROJECT = main
GOAL = main
CFLAGS = -Wall
CC = g++
CFLAGS = -Wall -g

$(GOAL): $(GOAL).cpp
	$(CC) $(CFLAGS) $(GOAL).cpp -o $(GOAL)

run: tags $(GOAL)
	./$(GOAL)

tags: $(GOAL).cpp
	ctags $(GOAL).cpp

clean:
	rm -f $(GOAL) tags

.PHONY: bundle
bundle: $(PROJECT).tgz

$(PROJECT).tgz: $(GOAL).cpp Makefile README.txt
	tar -czf $(PROJECT).tgz $(GOAL).cpp Makefile README.txt