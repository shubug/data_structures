/*** 1. Implementing Stack using array ***/
/*** 2. Additional functionality of Dynamic Stack (DS) ***/
/*** 3. Implementing Advance Minimum Stack that returns min element in stack in O(1) (AS) ***/
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct Stack{
 int top;
 int capacity;
 int *array;
};

struct AdvanceStack{
 struct Stack *elementStack;
 struct Stack *minStack;
};

struct Stack *createStack(int capacity){
 struct Stack *S = malloc(sizeof(struct Stack));
 if(!S)
  return NULL;
 S->top = -1;
 S->capacity = capacity;
 S->array = (int *)malloc(S->capacity*sizeof(int));

 return S;
}

int isStackFull(struct Stack *S){
 return S->top == S->capacity - 1;
}

void push(struct Stack *S, int data){
 if(isStackFull(S))
  printf("Stack Overflow!!");
 else
  S->array[++S->top] = data;
}

int isStackEmpty(struct Stack *S){
 return S->top == -1;
}

int pop(struct Stack *S){
 if(isStackEmpty(S))
  printf("Stack Underflow!!");
 else
  return S->array[S->top--];

 return INT_MIN;
}

int top(struct Stack *S){
 return S->array[S->top];
}

struct Stack *createDStack(){
 struct Stack *DS = malloc(sizeof(struct Stack));
 if(!DS)
  return NULL;
 DS->top = -1;
 DS->capacity = 1; // As this is a dynamic array, so we start the stack with minimum capacity and then keep on incresing it as per the requirement
 DS->array = (int *)malloc(sizeof(int));

 return DS;
}

void revampDStack(struct Stack *DS){
 DS->capacity *= 2;
 DS->array = realloc(DS->array, DS->capacity);
}

void Dpush(struct Stack *DS, int data){
 if(isStackFull(DS))
  revampDStack(DS);
 DS->array[++DS->top] = data;
}

struct AdvanceStack *createAdvStack(int capacity){
 struct AdvanceStack *AS = (struct AdvanceStack *)malloc(sizeof(struct AdvanceStack));
 if(!AS)
  return NULL;
 AS->elementStack = createStack(capacity);
 AS->minStack = createStack(capacity);
 return AS;
}

void ASpush(struct AdvanceStack *AS, int data){
 push(AS->elementStack, data);
 if(isStackEmpty(AS->minStack) || top(AS->minStack) >= data)
  push(AS->minStack, data);
}

int ASpop(struct AdvanceStack *AS){
 int temp;
 if(isStackEmpty(AS->elementStack))
  return -1;
 temp = top(AS->elementStack);
 if(top(AS->minStack) == pop(AS->elementStack))
  pop(AS->minStack);
 
 return temp;
}

int getMinimum(struct AdvanceStack *AS){
 return top(AS->minStack);
}

void insertAtBottom(struct Stack *S, int data){
 if(isStackEmpty(S))
  push(S, data);
 else{
  int temp = pop(S);
  insertAtBottom(S, data);
  push(S, temp);
 }
 return ;
}

void reverseStack(struct Stack *S){
 if(isStackEmpty(S))
  return ;
 int temp = pop(S);
 reverseStack(S);
 insertAtBottom(S, temp); //Replacement of push operation to put it back into the stack
 return ;
}

int main(){

 /*struct Stack *S = createStack(10);
 push(S, 23);
 push(S, 11);
 push(S, 45);
 printf("Popped Element: %d\n", pop(S));
 printf("Popped Element: %d\n", pop(S));*/
 //printf("Popped: %d\n", pop(S));
 
 /*struct Stack *DS = createDStack(); 
 Dpush(DS, 3);
 Dpush(DS, 6);
 Dpush(DS, 9); 
 printf("Popped Element: %d\n", pop(DS));
 printf("Popped Element: %d\n", pop(DS));
 printf("Popped Element: %d\n", pop(DS));
 printf("Popped Element: %d\n", pop(DS));*/
 
 /*struct AdvanceStack *AS = createAdvStack(10);
 ASpush(AS, 5);
 ASpush(AS, 2);
 ASpush(AS, 4);
 ASpush(AS, 2);
 ASpush(AS, 1);
 printf("Minimum Element: %d\n", getMinimum(AS));
 printf("Popped Element: %d\n", ASpop(AS));
 printf("Minimum Element: %d\n", getMinimum(AS));
 printf("Popped Element: %d\n", ASpop(AS));
 printf("Minimum Element: %d\n", getMinimum(AS));
 printf("Popped Element: %d\n", ASpop(AS));
 printf("Minimum Element: %d\n", getMinimum(AS));
 printf("Popped Element: %d\n", ASpop(AS));
 printf("Minimum Element: %d\n", getMinimum(AS));*/

 struct Stack *S = createStack(10);
 push(S, 23);
 push(S, 11);
 push(S, 45);
 push(S, 68);
 reverseStack(S);
 printf("Popped Element after reversing the stack: %d\n", pop(S));
 printf("Popped Element after reversing the stack: %d\n", pop(S));
 printf("Popped Element after reversing the stack: %d\n", pop(S));
 
 return 0;
}
