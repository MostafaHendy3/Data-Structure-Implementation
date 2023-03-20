
#ifndef Queue_H
#define Queue_H
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

#if LimitedMemory == 1
typedef struct queuenode
{
    QueueEntry e;
    struct queuenode *next;
} QueueNode;
typedef struct Q
{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;
#else
typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MaxQueue];
} Queue;
#endif
void CreateQueue(Queue *);
void Append(Queue *pq, QueueEntry e);
QueueEntry serve(Queue *);
int QueueFull(Queue *pq);
int QueueEmpty(Queue *pq);
int QueueSize(Queue *pq);
void ClearQueue(Queue *pq);
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry));
#endif