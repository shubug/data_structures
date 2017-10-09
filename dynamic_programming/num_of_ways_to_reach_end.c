/* Find number of ways to reach end of the array for each element of the array */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void numOfWays(int arr[], int n){
 int *ways = (int *)malloc(sizeof(int) * n);
 
 ways[n-1] = 0;

 for(int i=n-2; i>=0; i--){
  if(arr[i] == 0)
   ways[i] = -1;

  else{
    if(i+arr[i] >= n-1)
      ways[i] = 1;
    else
      ways[i] = 0;

    for(int j=i+1; j<n && j<=i+arr[i]; j++){
      if(ways[j] != -1)
        ways[i] += ways[j];
    }
    if(ways[i] == 0)
     ways[i] = -1;
  }
 }
 
 for(int i=0; i<n; i++)
  printf("%d ", ways[i]);
}

int main(){
 int arr[] = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};

 numOfWays(arr, sizeof(arr)/sizeof(arr[0]));
 return 0;
}
