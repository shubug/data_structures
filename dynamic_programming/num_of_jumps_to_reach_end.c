/* Task is to find the number of ways to reach the end of the array */
/* Here we start from the rightmost side and keep on adding the count of jumps */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int min(int a, int b){
 return a<b?a:b;
}

/* This is O(n*n) method using DP */
int numOfJumps(int arr[], int n){
 int i, j;
 int *jumps = (int *)malloc(sizeof(int) * n); 

 if(n <= 1)
  return 0;

 jumps[n-1] = 0; //As the number of jumps required to reach last element from itself is zero 
 
 for(i=n-2; i>=0; i--){
  
  if(arr[i] == 0)
    jumps[i] = INT_MAX;
  else if(i + arr[i] >= n-1)
    jumps[i] = 1;
  else{
    jumps[i] = INT_MAX;
    for(j=i+1; j<n && j<=(i+arr[i]); j++){
     if(jumps[j] != INT_MAX)
      jumps[i] = min(jumps[i], jumps[j]+1);
    }
  }
 }
 return jumps[0];
}

/* More efficient approach O(n) */
int max(int a, int b){
 return a<b?b:a;
}

int numJumps(int arr[], int n){
 if(n<=1)
  return 0;
 
 // The above check ensures that the length of the array is >1
 if(arr[0] == 0)
  return -1; 

 int maxReach = arr[0];
 int steps = arr[0];
 int jumps = 1;

 for(int i=1; i<n; i++){
  if(i == n-1)
   return jumps;

  maxReach = max(maxReach, (i+arr[i]));  
  steps--;

  if(steps == 0){
   jumps++;
   
   if(i >= maxReach)
     return -1;
   steps = maxReach - i;
  }
 }
 return -1;
}

int main(){
 //int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
 int arr[] = {1, 0, 3, 4, 1, 0, 3, 0, 0, 1};
 
 printf("%d\n", numJumps(arr, sizeof(arr)/sizeof(arr[0])));
 return 0;
}
