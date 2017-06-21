/*** Task is to find the maximum sum contiguous array ***/
#include <stdio.h>

int max(int a, int b){
 return a>b?a:b;
}

int max_sum_array(int arr[], int n){
 int i, curr_sum=0, max_sum=0; 
 curr_sum = arr[0];
 max_sum = arr[0];

 for(i=1; i<n; i++){
  curr_sum = max(arr[i], curr_sum+arr[i]); //This statement handles all the -ve element array as well
  max_sum = max(max_sum, curr_sum);
 }
 return max_sum;
}

int main(){
 //int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
 int arr[] = {-2, -5, -3, -1};
 int n = sizeof(arr)/sizeof(arr[0]);
 int max = max_sum_array(arr, n);
 printf("Max sum of any contiguous array is: %d\n", max);
 return 0;
}
