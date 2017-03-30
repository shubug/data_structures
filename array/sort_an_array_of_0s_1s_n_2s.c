/**** SORT OF AN ARRAY OF 0s 1s n 2s ****/
#include <stdio.h>

void swap(int *m, int *n){
 int temp = *m;
 *m = *n;
 *n = temp;
}

void sortArray(int arr[], int size){
 int l=0, mid=0, r=size-1;
 
 while(mid < r){
  switch(arr[mid]){
   case 0:
     if(l == mid){
        l++;
        mid++;
     }
     else
     	swap(&arr[l++], &arr[mid++]);
    break; 
   case 1:
     mid++;
     break;
   case 2:
     swap(&arr[mid], &arr[r--]);
  }
 }
}

int main()
{int arr[] = {0, 2, 2, 1, 0, 1, 1, 2, 0, 2};
 int i,n = sizeof(arr)/sizeof(arr[0]);
 
 sortArray(arr, n);
 
 //Print the Sorted array
 for(i=0;i<n;i++){
  printf("%d ",arr[i]); 
 }

 return 1;
}
