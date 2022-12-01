SOURCE_FILES=list.c queue.c stack.c vector.c 
HEADER_PATH=include/datastructs
HEADER_FILES=$(HEADER_PATH)/list.c $(HEADER_PATH)/queue.c $(HEADER_PATH)/stack.c $(HEADER_PATH)/vector.c 
SUBMIT_FILES=$(SOURCE_FILES) $(HEADER_FILES) grading.make Makefile README.md test.c

# Create a directory for submission files
$(USER):
	mkdir -p $(USER) 

# Target to prepare an archive for submitting the assignment
.PHONY: submit
submit: $(USER).tar

# Copy submission files, then archive them
$(USER).tar: $(USER) $(SUBMIT_FILES)
	cp -v $(SUBMIT_FILES) $<
	tar -cv -f $@ $<

feedback.log: test
	(date && whoami) | tee -a feedback.log
	test 2>&1 | tee -a feedback.log

# This is the make target for grader use.
# The grader should execute with `make -k check` 
# in order to continue past test errors.
.PHONY: check
check: test
	./test 2>&1 | tee -a feedback.log

.PHONY:really-clean
really-clean: clean
	rm -fv feedback.log