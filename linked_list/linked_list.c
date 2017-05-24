#include <stdio.h>
#include <stdlib.h>

struct listNode{
 int data;
 struct listNode *next;
};

void addNode(struct listNode **head, int data, int position){
 struct listNode *temp = *head;
 struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
 newNode->data = data;
 newNode->next = NULL;
 
 if((*head) == NULL){
  *head = newNode;
  return ;
 }
 //Also handles the case when value of position is negative
 if(position <= 0){
  newNode->next = *head;
  *head = newNode;
  return ;
 }
 
 position--;
 while(temp->next && position){
  temp=temp->next;
  position--;
 } 
 newNode->next = temp->next;
 temp->next = newNode;
 return;
}

void printlist(struct listNode *head){
 while(head){
  printf("%d ", head->data);
  head = head->next;
 }
 printf("\n");
}

struct listNode *reverseInPair(struct listNode *head){
 struct listNode *temp, *current=head;
 if(!head || !(head->next))
  return head;
 
 temp = current->next;
 current->next = temp->next;
 temp->next = current;
 current->next = reverseInPair(current->next);

 return temp;
}

struct listNode *middleElement(struct listNode *head){
 struct listNode *slowPtr, *fastPtr;
 slowPtr=fastPtr=head;
 
 while(fastPtr->next){
  fastPtr = fastPtr->next;
  if(fastPtr->next){
   fastPtr = fastPtr->next;
   slowPtr = slowPtr->next;
  }
 }
 return slowPtr; 
}

int main(){
 struct listNode *head = NULL;
 addNode(&head, 4, 0);
 addNode(&head, 7, 2);
 addNode(&head, 34, 1); 
 addNode(&head, 2, 1);
 addNode(&head, 52, 4); 
 //printlist(head);

 head = reverseInPair(head);
 printlist(head);

 //printlist(middleElement(head)); 

 return 0;
}
