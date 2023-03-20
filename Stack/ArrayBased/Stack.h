#ifndef Stack_H
#define Stack_H
#define StackEntry int
#define MAX_STACK_SIZE 4

typedef struct stack
{
   int top;
   StackEntry entry[MAX_STACK_SIZE];
}Stack;

void CreateStack(Stack *);
int StackSize(Stack *);
void ClearStack(Stack *);
void push(Stack *,StackEntry );
StackEntry pop(Stack *);
int StackFull(Stack *);
int StackEmpty(Stack *);
StackEntry peek(Stack *);

void StackTraverse(Stack *,void(*pf)(StackEntry));
#endif