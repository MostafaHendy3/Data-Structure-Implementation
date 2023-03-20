#include <stdio.h>
#include <stdlib.h>
#define QueueEntry int
#define MaxQueue 4

typedef struct queuenode{
    QueueEntry e;
    struct queuenode * next;
}QueueNode;

typedef struct Q
{
    QueueNode * front;
    QueueNode * rear;
    int size;
}Queue;


void CreateQueue(Queue *);
void Append(Queue * pq,QueueEntry e);

QueueEntry serve(Queue * );
int QueueFull(Queue *pq);
int QueueEmpty(Queue *pq);
int QueueSize(Queue *pq);
void ClearQueue(Queue * pq);
void TraverseQueue(Queue *pq,void(*pf)(QueueEntry));
