#include <stdio.h>
#include <stdlib.h>

struct listNode{
	int data;
	struct listNode *next;
};

int deleteNode(struct listNode **head, int position){
  struct listNode *current, *p, *q;
  current = 
  if(position == 1){

  }
}

void addNode(struct listNode **head, int data, int position){
  struct listNode *newNode, *current, *p, *q;
  newNode = (struct listNode *)malloc(sizeof(struct listNode));
  if(!newNode){
    printf("Memory Error !!");
  }
  newNode->data = data;
  current = *head;

  if(position == 1){
    newNode->next = current;
    *head = newNode;
    return ;
  }
  p = current;
  while(p && position - 1){
    q=p;
    p=p->next;
    position--;
  }
  newNode->next = p;
  q->next = newNode;
}

void printList(struct listNode *head){
  while(head){
    printf("%d-->", head->data);
    head = head->next;
  }
  printf("\n");
}

int main()
{ struct listNode *head = NULL;
  addNode(&head, 5, 1);
  addNode(&head, 3, 2);
  addNode(&head, 7, 3);
  addNode(&head, 6, 2);
  printList(head);

  deleteNode(&head, 2)
	printList(head);

  return 1;	
}
