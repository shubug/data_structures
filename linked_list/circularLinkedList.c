# include <stdio.h>
# include <stdlib.h>

typedef struct {
 int data;
 struct listNode *next;
}listNode;

void addNode(listNode **head, int data){
 listNode *temp;
 listNode *newNode = (listNode *)malloc(sizeof(listNode));
 newNode->data = data;
 if(*head == NULL){
  *head = newNode;
  newNode->next = newNode; //To make the list circular
  return ;
 }
 temp = *head;
 while(temp->next != *head)
  temp = temp->next;
 
 temp->next = newNode;
 newNode->next = *head;
 return ;
}

void printlist(listNode *head){
 listNode *temp = head;
 if(temp->next == head) //This is to handle the case when there is only 1 node in the linked list
  printf("xx %d ", temp->data);
 while(temp->next != head){
  printf("%d ", temp->data);
  temp = temp->next;
 }
 printf("\n");
}

int main(){
 listNode *head = NULL;
 addNode(&head, 2);
 addNode(&head, 4);
 printlist(head);
 
 return 0;
}
