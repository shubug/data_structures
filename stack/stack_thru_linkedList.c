/*** Implementing stack through linked list ***/
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct listNode{
 int data;
 struct listNode *next;
};

void push(struct listNode **head, int data){
 struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
 newNode->data = data;
 newNode->next = NULL;
 if(*head == NULL)
  *head = newNode;
 else{
  newNode->next = *head;
  *head = newNode;
 }
}

int isStackEmpty(struct listNode *head){
 return !head;
}

int pop(struct listNode **head){
 if(isStackEmpty(*head))
  printf("Stack Underflow!!\n");
 else{
  int data = (*head)->data;
  *head = (*head)->next;
  return data;
 }
 return INT_MIN;
}

int main(){
 struct listNode *head = NULL;
 push(&head, 34);
 push(&head, 45);
 printf("Popped Element: %d\n", pop(&head));
 printf("Popped Element: %d\n", pop(&head));
 return 0;
} 
