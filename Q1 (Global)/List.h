#include "global.h"
#if LIMITED_MEMORY == ArrayBased

typedef struct list
{
    ListEntry entry [MaxList];
    int size;
}List;

#else
//Linked List Implementation
#endif
void CreateList(List *);
int EmptyList(List *pl);
int FullList(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
ListEntry DeleteList(int pos,List *pl );
void InsertList(int pos,ListEntry e,List *pl );
void ReplaceList(int pos,ListEntry e,List *pl );
ListEntry RetriveList(int pos,List *pl );
void TraverseList(List *pl,void(*pf)(ListEntry));
