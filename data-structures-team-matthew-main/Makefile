$(info Set these environment variables and delete this message)
CFLAGS=
LDFLAGS=
LDLIBS=
ARFLAGS=

all: libdatastructs.a test

%.o : %.c
	$(error You must implement a rule to make \
		object files from source files)

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
	$(error You must implement the clean rule and delete this message)

# Secret grader Makefile additions ;)
# Just kidding! It's not secret, but you can safely ignore it.
include grading.make