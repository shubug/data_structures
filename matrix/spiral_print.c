#include <stdio.h>

void spiralPrint(int mat[4][4], int m, int n){
 int i, k=0, l=0;
 while(k < m && l < n){
 	for(i=l; i<n; i++){
 	  printf("%d ", mat[k][i]);
    }
    k++;
    for(i=k; i<m; i++){
 	  printf("%d ", mat[i][n-1]);
    }
    n--;
    if(k < m){
 	  for(i=n-1;i>=l;i--){
        printf("%d ", mat[m-1][i]);
 	  }
 	  m--;
    }
    if(l < n){
 	  for(i = m-1; i>=k ; i--){
 		printf("%d ", mat[i][l]);
 	  }
 	  l++;
    }
 }
}

int main(){
 int mat[4][4] = {{10, 20, 30, 40},
                  {15, 25, 35, 45},
                  {27, 29, 37, 48},
                  {32, 33, 39, 50},
                 };
 
 spiralPrint(mat, 4, 4);
 return 1;
}