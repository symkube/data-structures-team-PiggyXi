#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifndef DATASTRUCTS_DATA_T
#define DATASTRUCTS_DATA_T 
typedef uint64_t Data;
#endif // DATASTRUCTS_DATA_T

#ifndef DATASTRUCTS_STACK_H
#define DATASTRUCTS_STACK_H 

typedef struct StackNode {
  Data value;
  StackNode *next;
} StackNode;

typedef struct Stack {
  StackNode *top;
  int length;
} Stack;

StackNode *new_StackNode(Data d);
void del_StackNode(StackNode *sn);
StackNode *copy_StackNode(StackNode *sn);

Stack *new_Stack();
void del_Stack(Stack *s);
Stack *copy_Stack(Stack *s);

void clear(Stack *s);
void push(Stack *s, Data d);
Data pop(Stack *s);
Data peek(Stack *s);

#endif // DATASTRUCTS_STACK_H