CFLAGS=-g -Wall -std=c99
LDFLAGS=
LDLIBS=-lcunit
ARFLAGS= rcs

all: libdatastructs.a test

%.o : %.c
	$(CC) $(CFLAGS) $< -c

libdatastructs.a: list.o stack.o vector.o queue.o tree.o
	$(AR) $(ARFLAGS) $@ $^

main:
	$(info You may implement a demo in main.c and delete this message)
	pass;

test: test.c libdatastructs.a
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS) 

# Removes any files/directories 
# created using student files as prerequisites
.PHONY: clean
clean:
	rm -fv *.o
	rm -fv main
	rm -fv test

# Secret grader Makefile additions ;)
# Just kidding! It's not secret, but you can safely ignore it.
include grading.make