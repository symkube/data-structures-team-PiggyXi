#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifndef DATASTRUCTS_DATA_T
#define DATASTRUCTS_DATA_T
typedef uint64_t Data;
#endif // DATASTRUCTS_DATA_T

#ifndef DATASTRUCTS_LIST_H
#define DATASTRUCTS_LIST_H

typedef struct Node{
	Data data;
	Node *next, *prev;
} Node;

typedef struct List{
	Node *head, *tail;
} List;

Node *new_Node(Data *d);
void del_Node(Node *n);
Node *copy_Node(Node *n);

List *new_List();
void *del_List(List *l);
List *copy_List(List *l);

size_t len_List(List *l);
Node *getNode_List(List *l, Data d);
List *insert_Node(List *l, Node *n, Node *pos);
List *append_Node(List *l, Node *n);
List *remove_Node(List *l, Node *pos);
void print_Node(Node* n);
void print_List(List* l);

#endif // DATASTRUCTS_LIST_H