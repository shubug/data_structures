#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode{
 int data;
 struct BinaryTreeNode *left;
 struct BinaryTreeNode *right;
};

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

int main(){
 struct BinaryTreeNode *root = newNode(1);
 
 root->left = newNode(2);
 root->right = newNode(3);
 root->left->left = newNode(4);
 root->left->right = newNode(5);
 
 root->right->left = newNode(6);
 root->right->right = newNode(7);
 
 printPreOrder(root);
 printf("\n"); 

 return 0;
}
