#include <stdio.h>
#include <stdlib.h>

void printMatrix(int *source, int m, int n){
 for(int i=0; i<m; i++){
  for(int j=0; j<n; j++)
   printf("%d ", *(source + i*n + j));
  printf("\n"); 
 }
}

void rotateMatrix(int *source, int *dest, int m, int n){
 for(int i=0; i<m; i++){
  for(int j=0; j<n; j++){
   *(dest + j*m + m-i-1) = *(source + i*n + j);
  }
 }
}

int main(){
 int image [][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12}
                   };
 int m=3, n=4;
 int *pSource = (int *)image;
 int *pDestination = (int *)malloc(sizeof(int)*m*n);

 printMatrix(pSource, m, n);
 rotateMatrix(pSource, pDestination, m, n);
 printf("\n\n");
 printMatrix(pDestination, n, m);
 
 return 0;
}
