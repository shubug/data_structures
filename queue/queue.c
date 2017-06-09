#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
 int front,rear;
 int capacity;
 int *arr;
};

struct Queue *createQueue(int capacity){
 struct Queue *Q = malloc(sizeof(struct Queue));
 Q->front = Q->rear = -1;
 Q->capacity = capacity;
 Q->arr = (int *)malloc(Q->capacity * sizeof(int));

 return Q;
}

int isQueueEmpty(struct Queue *Q){
 return (Q->front == -1);
}

int isQueueFull(struct Queue *Q){
 return ((Q->rear + 1)%Q->capacity == Q->front);
}

int size(struct Queue *Q){
 return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void enqueue(struct Queue *Q, int data){
 if(isQueueFull(Q))
  printf("Queue Overflow!!");
 else{
  Q->rear = (Q->rear + 1) % Q->capacity;
  Q->arr[Q->rear] = data;
  
  if(Q->front == -1)
   Q->front = Q->rear; 
 }
}

int dequeue(struct Queue *Q){
 if(isQueueEmpty(Q))
  return INT_MIN;
 int temp = Q->arr[Q->front];
 if(Q->front == Q->rear) //means there was only one element in the queue
  Q->front = Q->rear = -1;
 else
  Q->front = (Q->front + 1) % Q->capacity;
 return temp;
}

void resizeQueue(struct Queue *Q){
 int size = Q->capacity;
 Q->capacity *= 2;
 Q->arr = realloc(Q->arr, Q->capacity);

 if(Q->front > Q->rear){
  for(int i=0; i<Q->front; i++)
   Q->arr[i+size] = Q->arr[i];

  Q->rear = Q->rear + size;
 }
}

void DynEnqueue(struct Queue *Q, int data){
 if(isQueueFull(Q))
  resizeQueue(Q);
 
  Q->rear = (Q->rear + 1) % Q->capacity;
  Q->arr[Q->rear] = data;

  if(Q->front == -1)
   Q->front = Q->rear;
}

int main(){
 struct Queue *Q = createQueue(4);
 /*enqueue(Q, 3);
 enqueue(Q, 6);
 enqueue(Q, 9);
 enqueue(Q, 12);
 enqueue(Q, 13);
 printf("Dequeue: %d\n", dequeue(Q));
 enqueue(Q, 15);
 printf("Dequeue: %d\n", dequeue(Q));
 printf("Dequeue: %d\n", dequeue(Q));
 */
 
 DynEnqueue(Q, 3);
 DynEnqueue(Q, 6);
 DynEnqueue(Q, 9);
 DynEnqueue(Q, 12);
 DynEnqueue(Q, 13);
 printf("Dequeue: %d\n", dequeue(Q));
 DynEnqueue(Q, 15);
 printf("Dequeue: %d\n", dequeue(Q));
 printf("Dequeue: %d\n", dequeue(Q));
 
 return 0;
}
