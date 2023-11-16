#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"


Node *head(List *mylist)
{
  if (mylist == NULL)
    return(NULL);
  return(mylist->head);
}

bool empty(List *mylist)
{
  if (mylist == NULL)
    return(true);
  return(head(mylist)==NULL);
}

Node *next(Node *mynode)
{
  if (mynode == NULL)
    return(NULL);
  return(mynode->next);
}

Node *prev(Node *head, Node *mynode)
{
  Node *current=head;
  while(current!=NULL){
    if (current->next == mynode)
      return(current);
    current = current->next;
  }
  return(NULL);
}


Node *tail(List *mylist) 
{
  Node *current=head(mylist);

  while (current != NULL) {
    if ((current -> next) == NULL)
      return(current);
    current = current->next; 
  }
  return(NULL);  
}


Item_t *Remove(List *mylist, Node *mynode)
{ Item_t *value;
  Node *lprev, *lhead;
  
  lhead=head(mylist);
  if (lhead == NULL) {
    return(NULL);
  } else if (lhead == mynode) {
    mylist->head = mynode->next;
  } else {
    lprev = prev(lhead,mynode);
    if (lprev != NULL) {
      lprev->next = mynode-> next;
    } else {
      fprintf(stderr,"Node not found\n");
      return(NULL);
    }
    value = mynode->item;
    free(mynode);
    
    return(value);  
  }
}

Node *Insert(List *mylist, Node *pos, int value)
{
  Item_t *new_item;
  Node *new,*lhead;

  
  if (mylist==NULL) {
    return(NULL);
  }else{
    lhead=head(mylist);

    new_item = (Item_t *)malloc(sizeof(Item_t));
    new = (Node *)malloc(sizeof(Node));
    new->item = new_item;
    new_item->value = value; 
    if ((head==NULL)||(pos==NULL)) {
      assert(pos==NULL);
      new->next=lhead;
      mylist->head=new;
      mylist->tail=new;
    } else {
      new->next = pos->next;
      pos->next = new;
      if (pos == tail(mylist))
	mylist->tail=new;
    }
  }
  return(new);  
}
    

Node *Find(List *mylist, int value)
{
  Node *current;
  if (mylist==NULL) {
    return(NULL);
  }else{
    current=head(mylist);
    while(current != NULL) {
      if (current->item->value == value)
	return(current);
      current = current->next;
    }
    return(NULL);
  }
}

void printNode(Node *pos)
{
  if (pos != NULL) 
    if (pos->item != NULL)
      printf("Position: %p  item:   %d \n",pos,pos->item->value);
}

void printList(List *mylist)
{
  Node *current;

  if (empty(mylist)){
    printf("Empty list\n");
    return;
  }
  current=head(mylist);
  while(current != NULL) {
    printNode(current);
    current = current->next;
  }
}

List *createList()
{
  List *mylist=(List *)malloc(sizeof(List));
  if (mylist != NULL) {
    mylist->head=NULL;
    mylist->tail=NULL;
  }
  return(mylist);
}

