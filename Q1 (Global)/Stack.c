#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>

#if LIMITED_MEMORY  == LinkedBased
void CreateStack(Stack *ps)
{
    ps->top = NULL;
    ps->size = 0;
}

void push(Stack *ps, StackEntry e)
{
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
    printf("Element pushed\n");
}

StackEntry pop(Stack *ps)
{
    StackNode *temp = ps->top;
    StackEntry e = ps->top->entry;
    ps->top = ps->top->next;
    free(temp);
    ps->size--;
    printf("Element poped\n");
    return e;
}
int StackEmpty(Stack *ps)
{
    return ps->top == NULL;
}
int StackFull()
{
    return 0;
}
void ClearStack(Stack *ps)
{
    //-------1st approach--------
    // for(int i =0;i<ps->size;i++){
    //     pop(ps);
    // }
    //-------2nd approach-------
    // while(ps->top){
    //     pop(ps);
    // }
    //-------3rd approach------
    StackNode *pn = ps->top;
    while (pn)
    {
        pn = pn->next;

        free(ps->top);

        ps->top = pn;
    }
    ps->size = 0;
    printf("Stack cleared");
}

void StackTraverse(Stack *ps, void (*pf)(StackEntry))
{
    if (ps->top == NULL)
    {
        printf("Stack is Empty");
        return;
    }
    StackNode *pn = ps->top;
    while (pn)
    {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}
int StackSize(Stack *ps)
{
    return ps->size;
}

#else
void CreateStack(Stack *ps)
{
    ps->top = -1;
}

int StackSize(Stack *ps)
{
    return ++ps->top;
}
void ClearStack(Stack *ps)
{
    ps->top = -1;
}

int StackFull(Stack *ps)
{
    // printf("Stack iS Full\n");
    return ps->top == MAX_STACK_SIZE - 1;
}

int StackEmpty(Stack *ps)
{
    return ps->top == -1;
}

StackEntry peek(Stack *ps)
{
    return ps->entry[ps->top];
}

void push(Stack *ps, StackEntry e)
{
    if (StackFull(ps) == 1)
    {
        printf("Stack is Full");
    }
    else
    {
        ps->top++;
        ps->entry[ps->top] = e;
    }
}

StackEntry pop(Stack *ps)
{
    if (StackEmpty(ps) == 1)
    {
        printf("Stack is Empty ");
    }
    else
    {
        StackEntry e = ps->top;
        ps->top--;
        return e;
    }
}
void StackTraverse(Stack *ps, void (*pf)(StackEntry))
{
    if (StackEmpty(ps) == 1)
    {
        printf("Stack is Empty");
        return;
    }

    for (int i = ps->top; i > -1; i--)
    {
        (*pf)(ps->entry[i]);
    }
}

#endif