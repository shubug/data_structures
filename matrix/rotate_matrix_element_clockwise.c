// Rotate the matrix elements in clockwise direction by 1. Similar to Spiral print of matrix, here instead of printing the element we replace it by previous element that is stored in temp variable

#include <stdio.h>

void printMatrix(int mat[4][4], int m, int n){
 int k=0,l=0;
 for(k=0; k<m; k++){
  for(l=0; l<n; l++)
   printf("%d ", mat[k][l]);
  printf("\n");
 }
 printf("\n\n");
}

void rotateMatrixElement(int mat[4][4], int m, int n){
 int i,a,k=0,l=0;
 int temp = 0; 

 while(k<m && l<n){
  temp = mat[k][l];

  for(i=l; i<n; i++){
   a = mat[k][i];
   mat[k][i] = temp;
   temp = a;
  }
  k++;
  
  for(i=k; i<m; i++){
   a = mat[i][n-1];
   mat[i][n-1] = temp;
   temp = a;
  } 
  n--;

  printf("\ntemp = %d\n", temp);
  
  for(i=n-1; i>=l; i--){
   a = mat[m-1][i];
   mat[m-1][i] = temp;
   temp = a;
  }
  m--;

  for(i=m-1; i>=k; i--){
   a = mat[i][l];
   mat[i][l] = temp;
   temp = a;
  }
  l++;

  mat[k-1][l-1] = temp;  
 } 
}

int main(){
 int mat[4][4] = {{1, 2,3 ,4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
 int m=4, n=4;
 
 printMatrix(mat, m, n);
 rotateMatrixElement(mat, m, n);
 printMatrix(mat, m, n);

 return 0;
}
