#include <stdio.h>
#define QueueEntry int
#define MaxQueue 4

typedef struct queue {
    int front;
    int rear;
    int size;
    QueueEntry entry[MaxQueue];
}Queue;

void CreateQueue(Queue *);
void Append(Queue * pq,QueueEntry e);

QueueEntry serve(Queue * );
int QueueFull(Queue *pq);
int QueueEmpty(Queue *pq);
int QueueSize(Queue *pq);
void ClearQueue(Queue * pq);
void TraverseQueue(Queue *pq,void(*pf)(QueueEntry));
