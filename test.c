#include "datastructs/list.h"
#include "datastructs/queue.h"
#include "datastructs/stack.h"
#include "datastructs/vector.h"
#include <CUnit/Basic.h>
#include <CUnit/CUCurses.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <CUnit/TestRun.h>
#include <stdbool.h>
#include <stdio.h>

Vector *myVector = NULL;
List *myList = NULL;
Stack *myStack = NULL;
Queue *myQueue = NULL;

/* The suite initialization function.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite_vector(void) { return 0; }

int init_suite_list(void) { return 0; }

int init_suite_stack(void) { return 0; }

int init_suite_queue(void) { return 0; }

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite_vector(void) { return 0; }

int clean_suite_list(void) { return 0; }

int clean_suite_stack(void) { return 0; }

int clean_suite_queue(void) { return 0; }

/* Tests of DS functions */
void testVECTOR(void) {
  // Test creation
  myVector = new_Vector(1);
  size_t sz = myVector->size;
  size_t len = myVector->len;
  CU_ASSERT_PTR_NOT_NULL_FATAL(myVector);
  CU_ASSERT(sz == 1);
  CU_ASSERT(len == 0);

  // Test insertions inside allocated memory
  insert_Vector(myVector, 0xdeadbeef, 0);
  CU_ASSERT_EQUAL(myVector->array[0], 0xdeadbeef);
  CU_ASSERT_EQUAL(myVector->used[0], true);
  CU_ASSERT_PTR_NOT_NULL_FATAL(at_Vector(myVector, 0));
  CU_ASSERT_EQUAL(*at_Vector(myVector, 0), 0xdeadbeef);
  sz = myVector->size;
  len = myVector->len;
  CU_ASSERT(sz == 1);
  CU_ASSERT(len == 0);

  // Test insertions beyond initially allocated memory
  CU_ASSERT_EQUAL(myVector->size, 1);
  CU_ASSERT_EQUAL(myVector->len, 1);
  for (size_t i = 1; i < 10; ++i) {
    insert_Vector(myVector, (Data)i, i);
    CU_ASSERT_EQUAL(*at_Vector(myVector, i), i);
  }
  sz = myVector->size;
  len = myVector->len;
  CU_ASSERT(sz >= 11);
  CU_ASSERT(len == 10);

  // Test resizing
  resize_Vector(myVector, 2048);
  sz = myVector->size;
  len = myVector->len;
  CU_ASSERT(sz == 2048);
  CU_ASSERT(len == 10);

  // Test removal
  remove_Vector(myVector, 3);
  CU_ASSERT_EQUAL(myVector->used[3], false);
  CU_ASSERT_EQUAL(sz, myVector->size);
  CU_ASSERT_EQUAL(len, myVector->len);

  // Test clearing
  clear_Vector(myVector);
  CU_ASSERT_EQUAL(sz, myVector->size);
  CU_ASSERT_EQUAL(myVector->len, 0);

  // Test deletion
  del_Vector(myVector);
  CU_ASSERT_PTR_NULL(myVector);
}

void testLIST(void) {
  Node *myNode = NULL;

  // Test node creation and deletion
  myNode = new_Node(0xdeadbeef);
  CU_ASSERT_PTR_NOT_NULL_FATAL(myNode);
  CU_ASSERT_EQUAL(myNode->data, 0xdeadbeef);
  CU_ASSERT_PTR_NULL(myNode->next);
  CU_ASSERT_PTR_NULL(myNode->prev);
  del_Node(myNode);
  CU_ASSERT_PTR_NULL(myNode);

  // Test list creation
  myList = new_List();
  CU_ASSERT_PTR_NOT_NULL(myList);

  // Test list appending
  for (size_t i = 0; i < 10; ++i) {
    append_Node(myList, i);
  }

  // Check forward traversal
  Node *nptr = myList->head;
  for (size_t i = 0; i <= 10; ++i) {
    CU_ASSERT_EQUAL(nptr->data, (Data)i);
    nptr = nptr->next;
  }

  // Check reverse traversal
  nptr = myList->tail;
  for (size_t i = 10; i >= 0; --i) {
    CU_ASSERT_EQUAL(nptr->data, (Data)i);
    nptr = nptr->prev;
  }

  // Test list insertion
  // Before: (head) <-> nprev <-> nptr <-> nnext
  // After:  (head) <-> nprev <-> myNode <-> nptr <-> nnext
  nptr = myList->head->next->next;
  Node *nprev = nptr->prev;
  Node *nnext = nptr->next;
  myNode = new_Node(0xdeadbeef);
  insert_Node(myList, myNode, nptr);
  CU_ASSERT_PTR_EQUAL(myNode->prev, nprev);
  CU_ASSERT_PTR_EQUAL(myNode->next, nptr);
  CU_ASSERT_PTR_EQUAL(nprev->next, myNode);
  CU_ASSERT_EQUAL(nnext->prev, myNode);

  // Test list removal
  // Before: nprev <-> myNode <-> nnext
  // After: nprev <-> nnext
  nprev = myNode->prev;
  nnext = myNode->next;
  remove_Node(myList, myNode);
  CU_ASSERT_PTR_EQUAL(nnext->prev, nprev);
  CU_ASSERT_PTR_EQUAL(nprev->next, nnext);

  // Test list deletion
  del_List(myList);
  CU_ASSERT_PTR_NULL(myList);
}

void testSTACK(void) {
  // Initialization
  myStack = new_Stack();
  CU_ASSERT_PTR_NOT_NULL_FATAL(myStack);
  CU_ASSERT_EQUAL(myStack->length, 0);
  CU_ASSERT_PTR_NULL(myStack->top);

  // Adding Elements to the Stack
  for (size_t i = 0; i < 5; ++i) {
    push_Stack(myStack, (Data)i);
  }
  CU_ASSERT_EQUAL(myStack->length, 5);
  CU_ASSERT_EQUAL(peek_Stack(myStack), (Data)4);

  // Removing Elements from the Stack
  for (size_t i = 4; i > 2; --i) {
    CU_ASSERT_EQUAL(pop_Stack(myStack), (Data)i);
  }
  CU_ASSERT_EQUAL(myStack->length, 3);

  // Clearing the Stack
  clear_Stack(myStack);
  CU_ASSERT_PTR_NOT_NULL(myStack);
  CU_ASSERT_EQUAL(myStack->length, 0);
  CU_ASSERT_PTR_NULL(myStack->top);

  // Finalization
  del_Stack(myStack);
  CU_ASSERT_PTR_NULL(myStack);
}

void testQUEUE(void) {
  // Initialization
  myQueue = new_Queue();
  CU_ASSERT_PTR_NOT_NULL_FATAL(myQueue);
  CU_ASSERT_EQUAL(myQueue->length, 0);
  CU_ASSERT_PTR_NULL(myQueue->head);
  CU_ASSERT_PTR_NULL(myQueue->tail);

  // Adding Elements to the Queue
  for (size_t i = 0; i < 5; ++i) {
    enqueue_Queue(myQueue, (Data)i);
  }
  CU_ASSERT_EQUAL(myQueue->length, 5);
  CU_ASSERT_EQUAL(peek_Queue(myQueue), (Data)4);

  // Removing Elements from the Queue
  for (size_t i = 0; i < 2; ++i) {
    CU_ASSERT_EQUAL(dequeue_Queue(myQueue), (Data)i);
  }
  CU_ASSERT_EQUAL(myQueue->length, 3);

  // Clearing the Queue
  clear_Queue(myQueue);
  CU_ASSERT_PTR_NOT_NULL(myQueue);
  CU_ASSERT_EQUAL(myQueue->length, 0);
  CU_ASSERT_PTR_NULL(myQueue->top);

  // Finalization
  del_Queue(myQueue);
  CU_ASSERT_PTR_NULL(myQueue);
}

int main(int argc, char *argv[]) {

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add a suite to the registry */
  CU_pSuite pSuite_vector = NULL;
  pSuite_vector =
      CU_add_suite("Suite_Vector", init_suite_vector, clean_suite_vector);
  if (NULL == pSuite_vector) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite pSuite_list = NULL;
  pSuite_list = CU_add_suite("Suite_List", init_suite_list, clean_suite_list);
  if (NULL == pSuite_list) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite pSuite_stack = NULL;
  pSuite_stack =
      CU_add_suite("Suite_Stack", init_suite_stack, clean_suite_stack);
  if (NULL == pSuite_stack) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_pSuite pSuite_queue = NULL;
  if (NULL == pSuite_queue) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  if ((NULL == CU_add_test(pSuite_vector, "test of vectors", testVECTOR)) ||
      (false)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(pSuite_list, "test of lists", testLIST)) ||
      (false)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(pSuite_stack, "test of stacks", testSTACK)) ||
      (false)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(pSuite_queue, "test of queues", testQUEUE)) ||
      (false)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit curses interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_console_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}