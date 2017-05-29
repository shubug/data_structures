# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct Stack{
 int top;
 int capacity;
 int *array;
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

int main(){

 /*struct Stack *S = createStack(10);
 push(S, 23);
 push(S, 11);
 push(S, 45);
 printf("Popped Element: %d\n", pop(S));
 printf("Popped Element: %d\n", pop(S));*/
 //printf("Popped: %d\n", pop(S));
 
 struct Stack *DS = createDStack(); 
 Dpush(DS, 3);
 Dpush(DS, 6);
 Dpush(DS, 9); 
 printf("Popped Element: %d\n", pop(DS));
 printf("Popped Element: %d\n", pop(DS));
 printf("Popped Element: %d\n", pop(DS));
 printf("Popped Element: %d\n", pop(DS));
 return 0;
}
