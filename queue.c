#include "datastructs/queue.h"
#include <stddef.h>
#include <stdlib.h>

///
/// @brief      { Create a new QueueNode containing specified data }
///
/// @param[in]  d     { The data to be stored in the node}
///
/// @return     { Return a pointer to the newly created node on success, 
///               or a null pointer on failure. }
///
QueueNode *new_QueueNode(Data d) { return NULL; }

///
/// @brief      { Delete an existing QueueNode. Its heap memory is freed. }
///
/// @param      qn    A pointer to the node to be deleted
///
void del_QueueNode(QueueNode *qn) { return; }

///
/// @brief      Copy an existing QueueNode
///
/// @param      qn    A pointer to the node to be copied
///
/// @return     { Return a pointer to the new, copied node on success,
///               or a null pointer on failure. }
///
QueueNode *copy_QueueNode(QueueNode *qn) { return NULL; }

///
/// @brief      { Create a new queue }
///
/// @return     { Return a pointer to the newly created queue on success, 
///               or a null pointer on failure }
///
Queue *new_Queue() { return NULL; }

///
/// @brief      { Delete an existing queue. Its heap memory is freed.
///               If the queue is not empty, then clear the queue first. }
///
/// @param      s     { A pointer to the queue to be deleted }
///
void del_Queue(Queue *q) { return; }

///
/// @brief      { Copy an existing queue }
///
/// @param      q     { A pointer to the existing queue }
///
/// @return     { Return a pointer to the new queue on success,
///               return a null pointer on failure. }
///
Queue *copy_Queue(Queue *q) { return NULL; }

///
/// @brief      { Clears the contents of the queue without deleting 
///               the queue itself. Reset the length of the queue to 0.
///               Free the memory of all nodes on the queue if the queue was non-empty. 
///
/// @param      q     { A pointer to the queue to be cleared. }
///
void clear(Queue *q) { return; }

///
/// @brief      { Create a node with the given value, 
///               then enqueue it into the queue at the tail. 
///               Increment the length of the queue. }
///
/// @param      q     { A pointer to the queue }
/// @param[in]  d     { The value to be placed in the node }
///
void enqueue(Queue *q, Data d) { return; }

///
/// @brief      { Dequeue a node from the front of the queue, and return the Data inside.
///               Decrement the length of the queue. The dequeued node is freed.}
///
/// @param      q     { A pointer to the queue }
///
/// @return     { The data value in the popped node. }
///
Data dequeue(Queue *q) { return 0; }

///
/// @brief      { Get the value of the front of the queue without dequeuing the node. }
///
/// @param      q     { A pointer to the queue }
///
/// @return     { The data value in the node at the front of the queue. }
///
Data peek(Queue *q) { return 0; }