#include "Stack.h"
#include  <stdio.h>

void CreateStack(Stack * ps){
    ps->top=-1;
}

int StackSize(Stack *ps){
    return ++ps->top;
}
void ClearStack(Stack * ps){
    ps->top=-1;
}

int StackFull(Stack *ps){
    //printf("Stack iS Full\n");
    return ps->top == MAX_STACK_SIZE-1;
}

int StackEmpty(Stack * ps){
    return ps->top==-1;
}

StackEntry peek(Stack * ps){
    return ps->entry[ps->top];
}

void push(Stack *ps,StackEntry e){
    if (StackFull(ps)==1){
        printf("Stack is Full");
    }else{
        ps->top++;
        ps->entry[ps->top]=e;
    }
}

StackEntry pop(Stack * ps){
    if(StackEmpty(ps)==1){
        printf("Stack is Empty ");
    }else{
        StackEntry e = ps->top;
        ps->top --;
        return e;
    }
}
void StackTraverse(Stack *ps,void(*pf)(StackEntry)){
    if(StackEmpty(ps)==1){
        printf("Stack is Empty");
        return;
    }
    
    for(int i =ps->top;i>-1;i--){
        (*pf)(ps->entry[i]);
    }
}


