/* Find out the nth ugly number */
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c){
 if(a<b)
  return a<c?a:c;
 else
  return b<c?b:c;
}

int main(){
 int i2=0,i3=0,i5=0;
 int multiple_of_2 = 2;
 int multiple_of_3 = 3;
 int multiple_of_5 = 5;

 int n, count, num;
 scanf("%d", &n);
 
 int *arr = (int *)malloc(sizeof(int)*n);
 arr[0] = 1;

 for(count=1; count<n; count++){
  num = min(multiple_of_2, multiple_of_3, multiple_of_5);
  arr[count] = num;  

  if(num == multiple_of_2){
   i2 = i2 + 1;
   multiple_of_2 = arr[i2] * 2;
  }
  if(num == multiple_of_3){
   i3 = i3 + 1;
   multiple_of_3 = arr[i3] * 3;
  }
  if(num == multiple_of_5){
   i5 = i5 + 1;
   multiple_of_5 = arr[i5] * 5;
  }
 }
 printf("Nth number is: %d\n", arr[n-1]);
 return 0;
}
