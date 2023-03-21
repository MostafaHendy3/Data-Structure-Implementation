#include "List.h"
#if LIMITED_MEMORY == ArrayBased    
void CreateList(List *pl){
    pl->size =0;
}
int EmptyList(List *pl){
    return !pl->size;
}
int FullList(List *pl){
    return pl->size == MaxList;
}
int ListSize(List *pl){
    return pl->size;
}
void DestroyList(List *pl){
    pl->size=0;
}
void InsertList(int pos,ListEntry e,List *pl ){
    for(int i = pl->size-1;i>=pos;i--){
        pl->entry[i+1]=pl->entry[i];
    }
    pl->entry[pos]=e;
    pl->size++;
}
ListEntry DeleteList(int pos,List *pl ){
    ListEntry e =pl->entry[pos];
    for(int i =pos+1;i<pl->size;i++){
        pl->entry[i-1]=pl->entry[i];
    }
    pl->size--;
    return e;
}
ListEntry RetriveList(int pos,List *pl ){
    return pl->entry[pos];
}
void ReplaceList(int pos,ListEntry e,List *pl ){
    pl->entry[pos]=e;
}
void TraverseList(List *pl,void(*pf)(ListEntry)){
    for(int i =0;i<pl->size;i++){
        (*pf)(pl->entry[i]);
    }
}
#else
//Linked List Implementation
#endif