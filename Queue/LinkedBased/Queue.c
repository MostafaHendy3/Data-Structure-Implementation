#include "Queue.h"
#include <stdio.h>

void CreateQueue(Queue * pq){
    pq->rear=NULL;
    pq->front=NULL;
    pq->size=0;
}

void Append(Queue *pq,QueueEntry e){
    QueueNode * pn =(QueueNode *)malloc(sizeof(QueueNode));
    pn->e =e;
    pn->next=NULL;
    if(!pq->rear){
        pq->front=pn;
    }else{
        pq->rear->next=pn;     
    } 
    pq->rear =pn;
    pq->size++;
}

QueueEntry serve(Queue *pq){
    Queue * pn =pq->front;
    QueueEntry e = pq->front->e;
    pq->front =pq->front->next;
    if(!pq->front){
        pq->rear=NULL;
    }
    free(pn);
    pq->size --;
    return e;
}
int QueueFull(Queue *pq){
    return 0;
}
int QueueEmpty(Queue *pq){
    return !pq->front;
}
int QueueSize(Queue * pq){
    return pq->size;
}
void ClearQueue(Queue *pq){
    while (pq->front)
    {
        pq->rear =pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size=0;
}
void TraverseQueue(Queue *pq,void(*pf)(QueueEntry)){
    if(!pq->size){
        printf("Queue is Empty\n");
        return;
    }
    for (QueueNode * pn =pq->front;pn;pn=pn->next)
    {
        (*pf)(pn->e);
    }
}
