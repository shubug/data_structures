#include <stdio.h>
#include <time.h>

void swap(int *a, int *b){
 int temp = *a;
 *a = *b;
 *b = temp;
}

int main(){
 int arr[] = {2, 21, 31, 42, 53, 67};
 int i,j,n = sizeof(arr)/sizeof(arr[0]);

 srand(time(NULL));
 for(i=n-1; i>=0; i--){
  j = rand() % (i+1); //We need to put a bracket over i+1 otherwise it will become (rand() % i) + 1 which will fail in case i=0 as the priority of '%' function is more than the addition operator
  printf("i = %d, j = %d\n", i, j);
  printf("Swapping the values: %d and %d\n", arr[i], arr[j]);
  printf("\n\n");
  swap(&arr[i], &arr[j]);
 }

 //Now print the array
 for(i = 0; i<n; i++)
  printf("%d ", arr[i]);

 return 0;
}
