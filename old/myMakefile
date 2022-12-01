$(info Set these environment variables and delete this message)
CC = gcc
CFLAGS = -std=c99 -W -Wall
CFLAGSS = -std=c99 -W
LIBS = -lm

all: libdatastructs.a test

%.o : %.c
	$(CC) $(CFLAGS) $< -c

libdatastructs.a:
	$(error You must implement the libdatastructs.a rule and delete this message)

main:
	$(info You may implement a demo in main.c and delete this message)
	pass;

test: 
	$(error You must implement the test rule and delete this message)

# Removes any files/directories 
# created using student files as prerequisites
.PHONY: clean
clean:
	rm -f *.exe *.o all

# Secret grader Makefile additions ;)
# Just kidding! It's not secret, but you can safely ignore it.
include grading.make