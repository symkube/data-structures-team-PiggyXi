#include "datastructs/stack.h"
#include <stddef.h>
#include <stdlib.h>

///
/// @brief      { Create a new StackNode containing specified data }
///
/// @param[in]  d     { The data to be stored in the node}
///
/// @return     { Return a pointer to the newly created node on success, 
///               or a null pointer on failure. }
///
StackNode *new_StackNode(Data d) { return NULL; }

///
/// @brief      { Delete an existing StackNode. Its heap memory is freed. }
///
/// @param      sn    A pointer to the node to be deleted
///
void del_StackNode(StackNode *sn) { return; }

///
/// @brief      Copy an existing StackNode
///
/// @param      sn    A pointer to the node to be copied
///
/// @return     { Return a pointer to the new, copied node on success,
///               or a null pointer on failure. }
///
StackNode *copy_StackNode(StackNode *sn) { return NULL; }

///
/// @brief      { Create a new stack }
///
/// @return     { Return a pointer to the newly created stack on success, 
///               or a null pointer on failure }
///
Stack *new_Stack() { return NULL; }

///
/// @brief      { Delete an existing stack. Its heap memory is freed.
///               If the stack is not empty, then clear the stack first. }
///
/// @param      s     { A pointer to the stack to be deleted }
///
void del_Stack(Stack *s) { return; }

///
/// @brief      { Copy an existing stack }
///
/// @param      s     { A pointer to the existing stack }
///
/// @return     { Return a pointer to the new stack on success,
///               return a null pointer on failure. }
///
Stack *copy_Stack(Stack *s) { return NULL; }


///
/// @brief      { Clears the contents of the stack without deleting 
///               the stack itself. Reset the length of the stack to 0.
///               Free the memory of all nodes on the stack if the stack was non-empty. 
///
/// @param      s     { A pointer to the stack to be cleared. }
///
void clear(Stack *s) { return; }


///
/// @brief      { Create a node with the given value, 
///               then push it onto the stack. 
///               Increment the length of the stack. }
///
/// @param      s     { A pointer to the stack }
/// @param[in]  d     { The value to be placed in the node }
///
void push(Stack *s, Data d) { return; }

///
/// @brief      { Pop a node from the stack, and return the Data inside.
///               Decrement the length of the stack. The popped node is freed.}
///
/// @param      s     { A pointer to the stack }
///
/// @return     { The data value in the popped node. }
///
Data pop(Stack *s) { return 0; }

///
/// @brief      { Get the value of the top of the stack without popping the node. }
///
/// @param      s     { A pointer to the stack }
///
/// @return     { The data value in the node at the top of the stack. }
///
Data peek(Stack *s) { return 0; }