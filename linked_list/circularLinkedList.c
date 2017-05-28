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
 if(temp){
  printf("%d ", temp->data);
  temp = temp->next;
 }
 while(temp != head){
  printf("%d ", temp->data);
  temp = temp->next;
 }
 printf("\n");
}

listNode *morpheusCycle(listNode **head, int n, int m){
 int i;
 listNode *temp = *head;
 for(i=1;i<n;i++){
  int M=m-1; 
  while(M>1){
   temp=temp->next;
   M--;
  }
  listNode *temp2 = temp->next;
  printf("Deleted Node: %d\n", temp2->data);
  temp->next=temp2->next; //This extra temp2 variable is needed b'coz direct temp->next->next is showing some struct typedef incompatibility error
  temp = temp->next;
 }
 return temp;
}

int main(){
 listNode *head = NULL;
 addNode(&head, 2);
 addNode(&head, 4);
 addNode(&head, 6);
 addNode(&head, 3);
 addNode(&head, 11);
 addNode(&head, 5);
 printlist(head);
 
 listNode *res = morpheusCycle(&head, 6, 3);
 printf("last node: %d\n", res->data); //here N=6 is the length of the list and M=3
 return 0;
}
