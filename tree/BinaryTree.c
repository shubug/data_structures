#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode{
 int data;
 struct BinaryTreeNode *left;
 struct BinaryTreeNode *right;
};

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
 inOrderIter(root);
 
 return 0;
}
