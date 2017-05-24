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

struct listNode *reverseTheList(struct listNode *head){
 struct listNode *p, *q, *r;
 if(!head || !(head->next))
  return head;

 p=head;
 q=NULL;
 r=head->next;
 while(r){
  p->next = q;
  q=p;
  p=r;
  r=p->next;
 }
 p->next=q;
 return p;
}

int checkIfPalindrome(struct listNode *head){
 struct listNode *ptr1, *ptr2, *mid;
 if(!head || !(head->next))
  return 1;  //if lenght of linked list is less than 1, it's a palindrome
 
 mid = middleElement(head);
 mid->next = reverseTheList(mid->next);

 ptr1 = head;
 ptr2 = mid->next;
 while(ptr2){
  if(ptr1->data != ptr2->data)
   return 0;
  ptr1 = ptr1->next;
  ptr2 = ptr2->next;
 }
 return 1;
}

int main(){
 int res;
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
 /*head = reverseTheList(head);
 printlist(head);*/

 res = checkIfPalindrome(head);
 if(res)
  printf("The given list is palindrome");
 else
  printf("Given list isn't a palindrome");
 
 return 0;
}
