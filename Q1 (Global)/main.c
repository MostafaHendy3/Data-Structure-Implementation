#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "global.h"
void Display(StackEntry e);
int main()
{
    Stack s;
    Stack *ps = &s;
    CreateStack(ps);
    // pop(ps);
    push(ps, 1);
    push(ps, 2);
    push(ps, 3);
    push(ps, 4);

    // push(ps,5);
    // push(ps,6);
    StackTraverse(ps,&Display);
    Queue q;
    Queue *pq = &q;
    CreateQueue(pq);
    // serve(pq);
    Append(pq, 1);
    Append(pq, 2);
    Append(pq, 3);
    Append(pq, 4);
    TraverseQueue(pq, &Display);
    // StackTraverse(ps,&Display);
}

void Display(StackEntry e)
{
    printf("%d \n", e);
}