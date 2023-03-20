#ifndef Stack_H
#define Stack_H
#define StackEntry int
#define MAX_STACK_SIZE 4

typedef struct stackNode
{
   StackEntry entry;
   struct stackNode * next;
}StackNode;

typedef struct stack{
   int size;
   StackNode * top;
}Stack;

void CreateStack(Stack *);
int StackSize(Stack *);
void ClearStack(Stack *);

void push(Stack *,StackEntry );
StackEntry pop(Stack *);

int StackFull();
int StackEmpty(Stack *);
StackEntry peek(Stack *);

void StackTraverse(Stack *,void(*pf)(StackEntry));

//StackSum of element
StackEntry StackSum(Stack *);
#endif