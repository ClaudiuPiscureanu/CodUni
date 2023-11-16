#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define SIZEC  256
int main(int argc, char **argv)
{
  List *mylist;
  Node *current, *pos;
  Item_t *temp;
  int value, value1, go;
  char buffer[SIZEC];
  char code;

  mylist=createList();
  go = 1;
  while (go && (fgets(buffer,SIZEC,stdin) != NULL)){
    sscanf(buffer,"%c",&code);
    printf("Action code: %c \n",code);
    switch(code)
      {
      case 'i':
	fgets(buffer,SIZEC,stdin);
	sscanf(buffer,"%d",&value);
	Insert(mylist,tail(mylist),value);
	printf("Inserted : %d \n",value);
	break;
      case 'e':
	fgets(buffer,SIZEC,stdin);
	sscanf(buffer,"%d   %d",&value1,&value);
	pos=Find(mylist,value1);
	Insert(mylist,pos,value);
	printf("Inserted : %d \n",value);
	break;
	
      case 'f':
	fgets(buffer,SIZEC,stdin);
	sscanf(buffer,"%d",&value);
	pos=Find(mylist,value);
	printf("Position : %p \n",pos);
	printNode(pos);
	break;
      case 'r':
	fgets(buffer,SIZEC,stdin);
	sscanf(buffer,"%d",&value);
	pos=Find(mylist,value);
	printf("Position : %p \n",pos);
	printNode(pos);
	temp=Remove(mylist,pos);
	free(temp);
	printList(mylist);
	break;
      case 'p':
	printList(mylist);
	break;
      case 'q':
	go = 0;
	break;
      }
  }
  return(0);
}
