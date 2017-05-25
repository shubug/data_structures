/*** Task is to find the element that would be at the k’th position of the final sorted array ***/
#include <stdio.h>
#include <limits.h>

int KthElement(int arr1[], int l1, int arr2[], int l2, int k){
 int i, j, temp, count=0;
 for(i=0,j=0; count<k && i<l1 && j<l2;count++){
  if(arr1[i] < arr2[j]){
   temp = arr1[i];
   i++;    //Need to take care that value of 'i' should be increamented after storing the previous array index value in temp
  }
  else{
   temp = arr2[j];
   j++;
  }
 }
 if(count==k)
  return temp;
 
 if(i==l1){
  if((j+ k-count -1) >= l2)
   return INT_MAX;
  return arr2[j+(k-count)-1];
 }
 else{
  if((i+ k-count -1) >= l1)
   return INT_MAX;
  return arr1[i+(k-count)];
 }
}

int main(){
 int l1, arr1[] = {2, 4, 8, 16, 22};
 int l2, arr2[] = {1, 3, 7, 27, 64};

 l1 = sizeof(arr1)/sizeof(arr1[0]);
 l2 = sizeof(arr2)/sizeof(arr2[0]);

 printf("Kth element in the final sorted array would be: %d\n", KthElement(arr1, l1, arr2, l2, 8));
 
 return 0;
}
