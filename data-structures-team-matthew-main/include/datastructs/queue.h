#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifndef DATASTRUCTS_DATA_T
#define DATASTRUCTS_DATA_T 
typedef uint64_t Data;
#endif // DATASTRUCTS_DATA_T

#ifndef DATASTRUCTS_QUEUE_H
#define DATASTRUCTS_QUEUE_H 

typedef struct QueueNode {
	Data value;
	QueueNode *next;
} QueueNode;

typedef struct Queue {
	QueueNode *head,*tail;
	int length;
} Queue;

QueueNode *new_QueueNode(Data d);
void del_QueueNode(QueueNode *qn);
QueueNode *copy_QueueNode(QueueNode *qn);

Queue *new_Queue();
void del_Queue(Queue *q);
Queue *copy_Queue(Queue *q);


void clear(Queue *q);
void enqueue(Queue *q, Data d);
Data dequeue(Queue *q);
Data peek(Queue *q);

#endif // DATASTRUCTS_QUEUE_H