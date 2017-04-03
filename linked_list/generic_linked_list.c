/**** GENERIC LINKED LIST ****/
#include <stdio.h>
#include <stdlib.h>

struct listNode{
	void *data;
	struct listNode *next;
};

void printInt(void *n){
  printf("%d ", *(int *)n);
}

void printFloat(void *n){
  printf("%f ", *(float *)n);
}

//This function adds the new node at the begining of the list
void addNode(struct listNode **head, void *newdata, int dt_size){	
  struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));

  newNode->data = malloc(dt_size); //Allocating memory to the 'data' pointer of the new node
  newNode->next = *head;

  /* copy contents of newdata variable to the newly allocated memory */
  for(int i = 0; i < dt_size; i++){
  	*(char *)(newNode->data + i) = *(char *)(newdata + i);
  }

  *head = newNode; 
}

/* In 2nd param, the pattern is return_type (pointer_to_function_name)(input_param_of_the_function) just like any normal function call*/
void printList(struct listNode *head, void (*fptr)(void *)){
  while(head){
  	(*fptr)(head->data);
  	head = head->next;
  }
}

int main()
{ struct listNode *head = NULL;
  int arr[] = {3, 6, 9, 12, 15};
  float arr2[] = {10.2, 14.1, 7.54, 4.44, 6.32};
  unsigned dt_size = sizeof(arr2[0]);
  for(int i = 0;i <= 4; i++){ //size of the list passed statically here
    addNode(&head, &arr2[i], dt_size); //In 2nd param, we can't send just the value from array, b'coz we don't know the data type at the receiving end
  }
  //Here we are passing function pointer to printList function as 2nd parameter
  //printList(head, printInt);
  printList(head, printFloat);
}