#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode{
 int data;
 struct BinaryTreeNode *left;
 struct BinaryTreeNode *right;
};

struct Queue{
 struct BinaryTreeNode *data;
 int front, rear;
 int capacity;
 struct BinaryTreeNode **arr;
};

struct Queue *createQueue(int capacity){
 struct Queue *Q = malloc(sizeof(struct Queue));
 Q->capacity = capacity;
 Q->front = Q->rear = -1;
 Q->arr = (struct BinaryTreeNode **)malloc(Q->capacity * sizeof(struct BinaryTreeNode *));
 return Q;
}

int isQueueFull(struct Queue *Q){
 return ((Q->rear + 1) % Q->capacity == Q->front);
}

void enqueue(struct Queue *Q, struct BinaryTreeNode *node){
 if(isQueueFull(Q))
  printf("Queue Overflow!!\n");
 else{
  Q->rear = (Q->rear + 1) % Q->capacity;
  Q->arr[Q->rear] = node;
  if(Q->front == -1)
   Q->front = Q->rear;
 }
}

int isQueueEmpty(struct Queue *Q){
 return Q->front == -1;
}

struct BinaryTreeNode *dequeue(struct Queue *Q){
 if(isQueueEmpty(Q))
  printf("Queue Underflow!!\n");
 else{
  struct BinaryTreeNode *temp = Q->arr[Q->front];
  if(Q->front == Q->rear)
   Q->front = Q->rear = -1;
  else
   Q->front = (Q->front + 1) % Q->capacity;
  return temp;
 }
 return NULL;
}

struct BinaryTreeNode* stack[20];
int top = -1;

struct BinaryTreeNode *newNode(int data){
 struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
 newNode->data = data;
 newNode->left = newNode->right = NULL;
 return newNode;
}

void printPreOrder(struct BinaryTreeNode *root){
 if(root){
  printf("%d->", root->data);
  printPreOrder(root->left);
  printPreOrder(root->right);
 }
}

void printInOrder(struct BinaryTreeNode *root){
 if(root){
  printInOrder(root->left);
  printf("%d->", root->data);
  printInOrder(root->right);
 }
}

void printPostOrder(struct BinaryTreeNode *root){
 if(root){
  printPostOrder(root->left);
  printPostOrder(root->right); 
  printf("%d->", root->data);
 }
}

void push(struct BinaryTreeNode *node){
 stack[++top] = node;
}

int isStackEmpty(){
 return top == -1;
}

struct BinaryTreeNode *pop(){
 if(isStackEmpty())
  return NULL;
 return stack[top--];
}

void preOrderIter(struct BinaryTreeNode *root){
 struct BinaryTreeNode *temp;
 while(1){
  while(root){
   printf("%d->", root->data);
   push(root);
   root = root->left;
  }
  temp = pop();
  if(!temp)
   break;
  root = temp->right;
 }
 return ;
}

void inOrderIter(struct BinaryTreeNode *root){
 struct BinaryTreeNode *temp;
 while(1){
  while(root){
   push(root);
   root = root->left;
  }
  temp = pop();
  if(!temp)
   break;
  printf("%d->", temp->data);
  root = temp->right;
 }
 return ;
}

void levelOrder(struct BinaryTreeNode *root){
 if(!root)
  return ;
 struct Queue *Q = createQueue(10);
 struct BinaryTreeNode *temp = NULL;

 printf("Level order traversal of tree: ");
 enqueue(Q, root);
 while(!isQueueEmpty(Q)){
  temp = dequeue(Q);
  printf("%d->", temp->data);
  if(temp->left)
   enqueue(Q, temp->left);
  if(temp->right)
   enqueue(Q, temp->right);
 }
 printf("\n");
}

int heightOfTree(struct BinaryTreeNode *root){
 int left, right;
 if(!root)
  return 0;
 
 left = heightOfTree(root->left);
 right = heightOfTree(root->right);
 if(left > right)
  return 1 + left;
 else
  return 1 + right;
}

void deleteANode(struct BinaryTreeNode *root, struct BinaryTreeNode *node){
 
}

int main(){
 struct BinaryTreeNode *root = newNode(1);
 
 root->left = newNode(2);
 root->right = newNode(3);
 root->left->left = newNode(4);
 root->left->right = newNode(5);
 
 root->right->left = newNode(6);
 root->right->right = newNode(7);
 /*
 printPreOrder(root);
 printf("\n"); 

 printInOrder(root);
 printf("\n");

 printPostOrder(root);
 printf("\n");
 */ 
 
 //preOrderIter(root);
 //inOrderIter(root);
 //levelOrder(root);
 /*printf("Height of the above tree is: %d\n", heightOfTree(root));*/
 deleteANode(root, root->left->right);
 levelOrder(root);
 
 return 0;
}
