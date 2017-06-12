/*** Task is to find out the longest increasing subsequence in the given array ***/
/*** In the example below LIS is: 5 (-1 2 4 7 8) ***/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
 return a>b?a:b;
}

int lis(int arr[], int n){
 int i, j, res, LIS[n];
 //initially consider the LIS value = 1 for all the array elements, including just themselves
 for(i=0; i<n; i++)
  LIS[i] = 1;

 //In this for loop, chck if there is any element 'j' before 'i' where arr[i]>arr[j], then LIS[i] should be atleast LIS[j]+1
 for(i=1; i<n; i++){
  for(j=0; j<i; j++){
   if(arr[i] > arr[j])
    LIS[i] = max(LIS[i], LIS[j]+1);
  }
 }
 //finally the LIS of the array will be the maximum of LIS[i];
 res = LIS[0];
 for(i=0; i<n; i++){
  if(LIS[i] > res)
   res = LIS[i];
 }
 return res;
}

int main(){
 int arr[] = {10, -1, 3, 2, 4, 0, 7, 8};
 int n = sizeof(arr)/sizeof(arr[0]);

 printf("longest Increasing Subsequence of the given array is: %d\n", lis(arr, n));
 return 0;
}
