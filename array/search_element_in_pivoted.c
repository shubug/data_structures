/*** Task is to search an element in a sorted and rotated(pivoted) array ***/
/** Assumption: All elements in the array are unique **/
/* {2, 2, 2, 2, 2, 2, 0, 2} if duplicates are allowed, It's not possible to search in pivoted array in O(logn) as we will not be able to find out pivot by dividing array(using constant number of comparisons) */ 

#include <stdio.h>

int find_pivot(int arr[], int low, int high){
  if(low > high)
   return -1; //Pivot not found
  int mid = (low + high)/2;

  if(mid < high && arr[mid] > arr[mid+1])
   return mid;
  if(mid > low && arr[mid] < arr[mid-1])
   return mid-1;
  if(arr[low] >= arr[mid])
   return find_pivot(arr, low, mid-1); //find pivot in 1st half
  return find_pivot(arr, mid + 1, high); //2nd half
}

int binary_search(int arr[], int low, int high, int ele){
 if(low > high)
  return -1; //Element not found
 int mid;
 
 while(low <= high){
  mid = (low + high)/2;
  if(ele == arr[mid])
   return mid;

  if(ele > arr[mid])
   low = mid+1;
  else
   high = low-1;
 }
 return -1;
}

int find_ele(int arr[], int n, int ele){
 if(n<=0)
  return -1;
 int pivot = find_pivot(arr, 0, n-1); //pivot here means the highest element in the array(whose left and right both elements are smaller than it)
 if(pivot == -1)
  pivot = n-1;
 
 /* Finding pivot means we are dividing entire array into two different increasing sequences around both sides of pivot */

 if(ele == arr[pivot])
  return pivot;
 if(ele >= arr[0])
  return binary_search(arr, 0, pivot-1, ele); 
 return binary_search(arr, pivot+1, n-1, ele);
}

int main(){
 int arr[] = {3, 4, 5, 6, 1, 2};
 int n = sizeof(arr)/sizeof(arr[0]);
 printf("Element existed at index: %d\n", find_ele(arr, n, 4));
 return 0;
}
