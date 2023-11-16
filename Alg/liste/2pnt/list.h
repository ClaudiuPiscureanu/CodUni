#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct item{
  int value;
}Item_t;

typedef struct node {
  Item_t *item; 
  struct node *next;
} Node; 


typedef struct list {

  Node *head;
  Node *tail;

} List ; 

Node *head(List *mylist);
bool empty(List *mylist);
Node *next(Node *mynode);
Node *prev(Node *head, Node *mynode);
Node *tail(List *mylist);
Item_t *Remove(List *mylist, Node *mynode);
Node *Insert(List *mylist, Node *pos, int item);
Node *Find(List *mylist, int value);

List *createList();
void printNode(Node *pos);
void printList(List *mylist);

