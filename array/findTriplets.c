/*** The task is to find number of triplets in the array whose sum is equal to zero ***/
#include <stdio.h>

int cmp(const void *a, const void *b){
 return *(int *)a - *(int *)b;
}

void findTriplets(int arr[], int n){
 int found=0;
 qsort(arr, n, sizeof(arr[0]), cmp);

 for(int i=0; i<n; i++){
  int sum=0, l=i+1, r=n-1;
  while(l<r){
   sum = arr[i]+arr[l]+arr[r];
   if(sum == 0){
    printf("Triplet Exist: %d %d %d\n", arr[i], arr[l], arr[r]);
    l++;
    r--;
    found=1;
   }
   else if(sum > 0)
    r--;
   else
    l++;
  }
 }
 if(found == 0)
  printf("No such triplets exist in this array\n");
}

int main(){
 int arr[] = {0, -1, 2, -3, 1};
 int n = sizeof(arr)/sizeof(arr[0]);

 findTriplets(arr, n);
 return 0;
}
