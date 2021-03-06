#include <stdio.h>
#include <stdlib.h>

struct listNode{
	int data;
	struct listNode *next;
};

int middleElement(struct listNode *head){
  struct listNode *slow, *fast;
  slow = fast = head;
  while(fast->next){
    fast = fast->next;
    if(!(fast->next))
      return slow->data;
    fast = fast->next;
    slow = slow->next;
  }
  return slow->data;
}

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

int NthNodeFromEnd(struct listNode *head, int position){
  struct listNode *p, *q;
  p = head;
  q = head;
  while(position){
    if(!p){
      printf("List length is not good enough to calculate last nth element\n");
      return -1;
    }
    p = p->next;
    position--;
  }
  while(p){
    p = p->next;
    q = q->next;
  }
  return q->data;
}

struct listNode * reverseAList(struct listNode **head){
  struct listNode *p, *q, *r;
  p = *head;
  q = NULL;
  while(p){
   r = p->next;
   p->next = q;
   q = p;
   p = r;
  }
  return q;
}

struct listNode * reverseAListRec(struct listNode *curr, struct listNode **head){
 if(curr->next == NULL){
  *head = curr;
  return curr;
 }
 struct listNode *rev = reverseAListRec(curr->next, head); //We are passing the reference to head here so that we can change it when we hit the last node
 curr->next = NULL;
 rev->next = curr;
 return curr;
}

void swap2Nodes(struct listNode **head, int x, int y){
  if (x == y)
    return ;

  struct listNode *currX, *prevX, *currY, *prevY;
  currX = *head;
  prevX = NULL;
  while(currX && currX->data != x){
    prevX = currX;
    currX = currX->next;
  }

  currY = *head;
  prevY = NULL;
  while(currY && currY->data != y){
    prevY = currY;
    currY = currY->next;
  }

  if(!currX || !currY) //In case X or Y node don't exist in the list
    return ;
  
  if(prevX != NULL) //To check if X is the head node
    prevX->next = currY;
  else
    *head = currY;

  if(prevY != NULL) //To check if Y is the head node
    prevY->next = currX;
  else
    *head = currX;

  //Now set the currX and currY pointers
  struct listNode *temp = currX->next;
  currX->next = currY->next;
  currY->next = temp;

  return ;
}

int main()
{ struct listNode *head = NULL;
  addNode(&head, 5, 1);
  addNode(&head, 3, 2);
  addNode(&head, 7, 3);
  addNode(&head, 2, 2);
  addNode(&head, 6, 3);
  printList(head);

  //printf("Deleted Node: %d\n",deleteNode(&head, 4));
  /*printf("Middle Element: %d\n", middleElement(head));
	printList(head);*/
  
  /*int position = 3;
  int val = NthNodeFromEnd(head, position);
  if(val != -1)
    printf("Nth element from the end is %d\n", val);
  */
 
  /*head = reverseAList(&head);
  printList(head);*/

  reverseAListRec(head, &head);
  printList(head);

  /*swap2Nodes(&head, 5, 7);
  printList(head);*/

  return 1;	
}
