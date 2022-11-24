#include "datastructs/list.h"
#include <stddef.h>
#include <stdlib.h>

///
/// @brief      { Create a new node, containing specified data }
///
/// @param      d     { The data to be stored in the node }
///
/// @return     { Return a pointer to the newly created node on success, 
///               or a null pointer on failure. }
///
Node *new_Node(Data d) { return NULL; }

/// 
/// @brief      { Delete an existing node }
///
/// @param      n     { The node to be deleted. If n is null, no operation is performed. }
///
void del_Node(Node *n) { return NULL; }

///
/// @brief      { Copy an existing node }
///
/// @param      n     { A pointer to the node to be copied }
///
/// @return     { Return a pointer to the new, copied node on success,
///               or a null pointer on failure. }
///
Node *copy_Node(Node *n) { return NULL; } 

///
/// @brief      { Create a new list }
///
/// @return     { Return a pointer to the list on success, or a null pointer on failure. }
///
List *new_List() { return NULL; }

///
/// @brief      { Delete an existing list }
///
/// @param      l     { The list to be deleted. If l is null, no operation is performed. }
///
void *del_List(List *l) { return NULL; }

///
/// @brief      { Copy a list into a new list }
///
/// @param      l     { A pointer to the list to be copied }
///
/// @return     { A pointer to the new, copied list }
///
List *copy_List(List *l) { return NULL; }

///
/// @brief      { Return the length of a list }
///
/// @param      l     { The list to be measured }
///
/// @return     { The length of the list, which is the number of nodes. }
///
size_t len_List(List *l) { return 0; }

///
/// @brief      { Gets a pointer to the first node in the list 
///               with that data value. }
///
/// @param      l     { The list potentially containing a node }
/// @param[in]  d     { The data value to be searched for }
///
/// @return     A pointer to the found node
///
Node *getNode_List(List *l, Data d) { return NULL; }

///
/// @brief      { Inserts a node into the list before the node pointed to by pos.
///               If pos is also the head node, the head pointer is updated. }
///
/// @param      l     { The list to be inserted into }
/// @param      n     { The node to be inserted }
/// @param      pos   { A pointer to the node which will become the successor }
///
/// @return     { A pointer to the modified list }
///
List *insert_Node(List *l, Node *n, Node *pos) { return NULL; }

///
/// @brief      { Appends a node at tail of the list, and updates the tail pointer }
///
/// @param      l     { The list to be appended to }
/// @param      n     { The node to be appended }
///
/// @return     { A pointer to the modified list }
///
List *append_Node(List *l, Node *n) { return NULL; }

///
/// @brief      Removes a node from the list.
///
/// @param      l     { The list containing the node to be removed }
/// @param      pos   { A pointer to the node to be removed }
///
/// @return     { A pointer to the modified list }
///
List *remove_Node(List *l, Node *pos) { return NULL; }

///
/// @brief     { Pretty prints a node's data, and the addresses in the 
///              prev and next pointers. }
///
/// @param      n     { The node to be printed }
///
void print_Node(Node* n) {}

///
/// @brief      { Pretty prints a list. First, it prints the head/tail pointers,
///               then it traverses the list, calling print_Node on each node. }
///
/// @param      l     { The list to be printed }
///
void print_List(List* l) {}
