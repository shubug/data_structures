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

struct BinaryTreeNode *levelOrder(struct BinaryTreeNode *root){
 if(!root)
  return NULL;
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
 return temp;
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

int deleteDeepestNode(struct BinaryTreeNode *root, struct BinaryTreeNode *deepest){
 if(!root)
  return 0;
 if(root->left == deepest){
  root->left = NULL;
  return 1;
 }
 if(root->right == deepest){
  root->right = NULL;
  return 1;
 }
 if(!deleteDeepestNode(root->left, deepest))
  return deleteDeepestNode(root->right, deepest);

 return 1;
}

void deleteANode(struct BinaryTreeNode *root, struct BinaryTreeNode *node){
 //Find the deepest node of the tree 
 struct BinaryTreeNode *deepest = levelOrder(root);
 node->data = deepest->data;
 
 //Now delete the deepest node of the tree, as we have already copied the data of deepest node to the node to be deleted
 deleteDeepestNode(root, deepest); //Go through any traversal, find if either the left or right child of that node is the deepest node, if yes then point the child pointer to NULL 
 return ;
}

/*Diameter of a tree is the maximum distance(longest path b/w 2 leaf nodes) between any 2 nodes..this may not include the root node itself (probably in case of skewed trees)*/
int diameterOfTree(struct BinaryTreeNode *root, int *diameter){
 if(!root)
  return 0;
 int left, right;
 left = diameterOfTree(root->left, diameter);
 right = diameterOfTree(root->right, diameter);
 if(left + right + 1 > *diameter)
  *diameter = left+right+1;
 
 return left>right?left+1:right+1;
}

struct BinaryTreeNode *LCA(struct BinaryTreeNode *root, struct BinaryTreeNode *a, struct BinaryTreeNode *b){
 if(!root || !a || !b)
  return NULL;
 if(root == a || root == b)
  return root;
 
 struct BinaryTreeNode *left = LCA(root->left, a, b);
 struct BinaryTreeNode *right = LCA(root->right, a, b);
  
 if(left && right)
  return root;
 return left?left:right;
}

int hasPathSum(struct BinaryTreeNode *root, int sum){
 if(!root)
  return sum==0;
 
 sum = sum - root->data;
 return (sum==0 || hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
}

int arr[10];
void printArray(int arr[], int len){
 if(len == 0)
  return ;
 for(int i=0; i<len; i++)
  printf("%d->", arr[i]);
 
 printf("\n");
 return ;
}

void printAllPaths(struct BinaryTreeNode *root, int i){
 if(!root)
  return ;
 arr[i] = root->data;
 i++;

 if(!(root->left) && !(root->right)) 
  printArray(arr, i);
 else{
  if(root->left)
   printAllPaths(root->left, i);
  if(root->right)
   printAllPaths(root->right, i);
 }
 return ;
}

int levelWithMaxSum(struct BinaryTreeNode *root){
 if(!root)
  return 0;
 
 int current_sum=0, max_sum=0;
 struct BinaryTreeNode *temp;
 struct Queue *Q = createQueue(10);
 
 enqueue(Q, root);
 enqueue(Q, NULL);
 while(!isQueueEmpty(Q)){
  temp = dequeue(Q);
  if(!temp){
   //Means we have hit the end of one level
   if(!isQueueEmpty(Q))
    enqueue(Q, NULL);
   if(current_sum > max_sum)
    max_sum = current_sum;
   current_sum = 0;
  }
  else{
   current_sum += temp->data;
   if(temp->left)
    enqueue(Q, temp->left);
   if(temp->right)
    enqueue(Q, temp->right);
  }
 }
 return max_sum;
}

int search(int inOrder[], int start, int end, int data){
 for(int i=start; i<=end; i++)
  if(inOrder[i]==data)
   return i;

 return -1;
}

struct BinaryTreeNode *createTree(int inOrder[], int preOrder[], int start, int end){
 static int preIndex = 0;
 if(start > end)
  return NULL;
 struct BinaryTreeNode *newNode = malloc(sizeof(struct BinaryTreeNode));
 int data = preOrder[preIndex++];
 newNode->data = data;
 newNode->left = newNode->right = NULL;
 if(start == end)
  return newNode;
 //search for this preorder index in inOrder array
 int inIndex = search(inOrder, start, end, data);
 newNode->left = createTree(inOrder, preOrder, start, inIndex-1); 
 newNode->right = createTree(inOrder, preOrder, inIndex+1, end);
 
 return newNode;
}

void mirrorTree(struct BinaryTreeNode *root){
 if(!root)
  return ;
 mirrorTree(root->left);
 mirrorTree(root->right);
 
 struct BinaryTreeNode *temp = root->left;
 root->left = root->right;
 root->right = temp;
}

void zigzagTraversal(struct BinaryTreeNode *root){
 if(!root)
  return ;
 int left_to_right = 1;
 push(root)
 //Not possible here as we will need 2 stacks for that
}

int main(){
 struct BinaryTreeNode *up = newNode(0); //Just for LCA function
 struct BinaryTreeNode *root = newNode(1);
 
 up->left = root;
 up->right = newNode(8); 

 root->left = newNode(2);
 root->right = newNode(3);
 root->left->left = newNode(4);
 root->left->right = newNode(5);
 
 root->right->left = newNode(6);
 root->right->right = newNode(7);

 root->right->right->right = newNode(9); //Specifically for Diameter calculation, can remove it for all other functions
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
 /*deleteANode(root, root->left->right);
 levelOrder(root);*/
 /*printAllPaths(root, 0);*/
 /*printf("Does this sum exist in tree: %d\n", hasPathSum(root, 4));*/
 /*struct BinaryTreeNode *temp = LCA(up, root->left->right, up->right);
 if(temp)
  printf("LCA Node data: %d\n", temp->data);
 else
  printf("Both Nodes doesn't exits in the tree...so can't calculate their LCA\n");
 */
 /*int diameter = 0;
 diameterOfTree(root, &diameter);
 printf("Diameter of tree is: %d\n", diameter);
 */
 /*printf("Level with Maximum is level: %d\n", levelWithMaxSum(up));*/
 int inOrder[] = {4, 2, 5, 1, 6, 3, 7};
 int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
  
 /*levelOrder(createTree(inOrder, preOrder, 0 ,6));*/
 /*mirrorTree(root);
 levelOrder(root);*/
 //zigzagTraversal(root);

 return 0;
}
