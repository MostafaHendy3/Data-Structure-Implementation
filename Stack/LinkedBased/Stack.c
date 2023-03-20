#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
void CreateStack(Stack *ps){
    ps->top = NULL;
    ps->size=0;
}

void push(Stack *ps,StackEntry e){
    StackNode * pn =(StackNode *) malloc(sizeof(StackNode));
    pn->entry =e;
    pn->next = ps->top;
    ps->top =pn;
    ps->size ++;
    printf("Element pushed\n");
}

StackEntry pop (Stack*ps){
    StackNode * temp = ps->top;
    StackEntry e =ps->top->entry;
    ps->top=ps->top->next;
    free(temp);
    ps->size--;
    printf("Element poped\n");
    return e;
}
int StackEmpty(Stack *ps){
    return ps->top==NULL;
}
int StackFull(){
    return 0;
} 
void ClearStack(Stack * ps){
    //-------1st approach--------
    // for(int i =0;i<ps->size;i++){
    //     pop(ps);
    // }
    //-------2nd approach-------
    // while(ps->top){
    //     pop(ps);
    // }
    //-------3rd approach------
    StackNode * pn =ps->top;
    while(pn){
        pn=pn->next;

        free(ps->top);
        
        ps->top=pn;
    }
    ps->size =0;
    printf("Stack cleared");
}

void StackTraverse(Stack *ps,void(*pf)(StackEntry))
{
    if(ps->top==NULL){
        printf("Stack is Empty");
        return;
    }
    StackNode * pn=ps->top;
    while(pn){
        (*pf)(pn->entry);
        pn=pn->next;
    }

}
int StackSize(Stack * ps){
    return ps->size;
}

StackEntry StackSum(Stack*ps){
    
}