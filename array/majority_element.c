/**** MOORE-VOTING ALGORITHM ****/
#include <stdio.h>

int main()
{int arr[] = {3, 4, 4, 3, 3, 4, 4, 2, 5};
 int i,n = sizeof(arr)/sizeof(arr[0]);
 
 int num = 0;
 int suspect = arr[0];
 int count = 1;

 for(i=1;i<n;i++){
 	if(arr[i] == suspect){
 		count++;
 	}
 	else{
 		count--;
 		if(count<0){
 			count = 1;
 			suspect = arr[i];
 		}
 	}
 }
 if (count == 0){
 	//Now check if the suspected element is actually the majority element by counting its occurances in array
 	for(i=0;i<n;i++){
 		if(arr[i] == suspect)
 			num++;
 	}
 	if(num > n/2)
 	    printf("the majority element is %d\n", suspect);
 	else
 		printf("There is no majority element in this array\n");
 }
 else{
 	printf("There is no majority element in this array\n");
 }

 return 1;
}
