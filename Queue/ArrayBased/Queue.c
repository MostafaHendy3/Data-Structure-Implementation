#include "Queue.h"
#include <stdio.h>

void CreateQueue(Queue * pq){
    pq->front=0;
    pq->rear =-1;
    pq->size=0;

}

void Append(Queue * pq,QueueEntry e){
    if(QueueFull(pq)){
        printf("Queue is Full ,cant append\n");
        return ;
    }else{
        pq->rear= (pq->rear+1)%MaxQueue;
        pq->entry[pq->rear]=e; 
        //printf("item appended %d\n",pq->entry[pq->rear]);
        pq->size++;
    }
}

QueueEntry serve(Queue * pq){
    if(QueueEmpty(pq)){
        printf("Queue is Empty ,cant serve\n");
        return -1;
    }else{
        QueueEntry e = pq->entry[pq->front];
        //printf("item served %d\n",pq->entry[pq->front]);
        pq->front =(pq->front+1)%MaxQueue;
        pq->size--;
        return e;
    }
}
int QueueFull(Queue *pq){
    return pq->size == MaxQueue;
}
int QueueEmpty(Queue *pq){
    return !pq->size; 
}

int QueueSize(Queue *pq){
    return pq->size;
}
void ClearQueue(Queue * pq){
    pq->front=0;
    pq->rear =-1;
    pq->size=0;
}

void TraverseQueue(Queue *pq,void(*pf)(QueueEntry)){
    int s;
    if(!pq->size){
        printf("Queue is Empty\n");
        return;
    }
    for (int i = pq->front,s=0; s<pq->size; s++)
    {
        (*pf)(pq->entry[i]);
        i=(i+1)%MaxQueue;
    }
    
}