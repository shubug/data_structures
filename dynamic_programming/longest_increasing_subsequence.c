#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
 return a>b?a:b;
}

int lis(int arr[], int n){
 int i, j, res, temp[n];

 for(i=0; i<n; i++)
  temp[i] = 1;

 for(i=1; i<n; i++){
  for(j=0; j<i; j++){
   if(arr[i] > arr[j])
    temp[i] = max(temp[i], temp[j]+1);
  }
 }
 res = temp[0];
 for(i=0; i<n; i++){
  if(temp[i] > res)
   res = temp[i];
 }
 return res;
}

int main(){
 int arr[] = {10, -1, 3, 2, 4, 0, 7, 8};
 int n = sizeof(arr)/sizeof(arr[0]);

 printf("longest Increasing Subsequence of the given array is: %d\n", lis(arr, n));
 return 0;
}
