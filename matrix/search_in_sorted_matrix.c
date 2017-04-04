#include <stdio.h>

int search(int mat[4][4], int n, int x){
 int i,j;
 for(i=0,j=n-1; i<n,j>=0;){
   if(mat[i][j] == x){
   	printf("Element found at %d,%d\n", i, j);
   	return 1;
   }
   if (mat[i][j] > x)
   	  j--;
   else
   	  i++;
 }
 return 0;
}

int main(){
 int mat[4][4] = {{10, 20, 30, 40},
                  {15, 25, 35, 45},
                  {27, 29, 37, 48},
                  {32, 33, 39, 50},
                 };
 int x = 32;
 if (search(mat, 4, x) == 0)
 	printf("Element not found in the matrix\n");
 return 1;
}

