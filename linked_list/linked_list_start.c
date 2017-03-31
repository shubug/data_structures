#include <stdio.h>
#include <stdlib.h>

struct listNode{
	int data;
	struct listNode *next;
};

int deleteNode(struct listNode **head, int position){
  struct listNode *current, *p, *q;
  int val;

  current = *head;
  if(position == 1){
   *head = (*head)->next; //this bracket here is neccessary ***
   val = current->data;
   free(current);
   return val;
  }
  p = current;
  while(p && position - 1){
    q=p;
    p=p->next;
    position--;
  }
  q->next = p->next;
  val = p->data;
  free(p);
  return val;
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

  printf("Deleted Node: %d\n",deleteNode(&head, 4));
	printList(head);

  return 1;	
}
