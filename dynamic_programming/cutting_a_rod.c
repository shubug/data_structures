#include <stdio.h>
#include <limits.h>

int max(int a, int b){
 return a<b?b:a;
}

// Through Recursion
int cutRod(int price[], int size){
 int max_val = INT_MIN;

 if(size <= 0)
  return 0;

 for(int i=1; i<=size; i++){
  max_val = max(max_val, price[i-1] + cutRod(price, size-i));
 }
 return max_val;
}

// Through DP
int cutRodDP(int price[], int size){
 int val[size+1];
 val[0] = 0;
 if(size <= 0)
  return 0;

 for(int i=1; i<=size; i++){
  int max_val = INT_MIN;
  for(int j=0; j<i; j++){
    max_val = max(max_val, price[j] + val[i-j-1]);
  }
  val[i] = max_val;
 }
 return val[size];
}

int main(){
 int arr[] = {3, 5, 8, 9, 10, 17, 17, 20};

 printf("Maximun Value would be: %d\n", cutRodDP(arr, sizeof(arr)/sizeof(arr[0])));
 return 0;
}
