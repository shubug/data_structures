# include <stdio.h>
# include <stdlib.h>

struct listNode{
 int data;
 struct listNode *next;
 struct listNode *random;
};

struct listNode *addNode(struct listNode **head, int data){
 struct listNode *newNode = malloc(sizeof(struct listNode));
 newNode->data = data;
 newNode->next = NULL;
  
 struct listNode *temp = *head;
 if(temp == NULL){
  *head = newNode;
  return newNode;
 }
 while(temp->next != NULL)
  temp = temp->next;

 temp->next = newNode;
 return newNode;
}

struct listNode *randomize(struct listNode *head){
 return NULL;
}

struct listNode *cloneAList(struct listNode *head){
 struct listNode *temp = head;
 struct listNode *temp2;

 while(temp){
  temp2 = malloc(sizeof(struct listNode));
  temp2->data = temp->data;
  temp2->next = temp->random;
  temp->random = temp2;

  temp = temp->next;
 }

 temp = head;
 while(temp){
  temp2 = temp->random;
  temp2->random = temp2->next->random;
  /**temp2->next = temp->next->random; Can't set it here as temp2->next stores the random pointer of temp1, which we will be resetting in next loop**/
  temp = temp->next;
 }

 /*Now we have to take care of the damage done to list1*/
 temp = head;
 struct listNode *res = temp->random;

 while(temp){
  temp2 = temp->random;
  temp->random = temp2->next;
  if(temp->next != NULL)
   temp2->next = temp->next->random;
  else
   temp2->next = NULL;

  temp = temp->next;
 }

 return res;
}

void printList(struct listNode *head){
 while(head){
  printf("%d ", head->data);
  head = head->next;
 }
 printf("\n");
}

int main(){
 struct listNode *head = NULL;
 struct listNode *first = addNode(&head, 1);
 struct listNode *second = addNode(&head, 2);
 struct listNode *third = addNode(&head, 3);
 struct listNode *fourth = addNode(&head, 4);
 
 first->random = fourth;
 second->random = first;
 third->random = second;
 fourth->random = third;
 printList(head);
 
 struct listNode *head2 = cloneAList(head);
 printList(head2);
 
 return 1;
}
