#include <stdio.h>
#include <limits.h>

int MCMC(int arr[], int i, int j){
 if(i == j) //Means there is only one matrix in the array
  return 0;
 int k, cost, min;
 min = INT_MAX;
 
 for(k=i; k<j; k++){
  cost = MCMC(arr, i, k) + MCMC(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
  if(cost < min)
   min = cost;
 }
 return min;
}

int MCMC_UsingDP(int arr, int i, int j){

}

int main(){
 int arr[] = {1, 2, 3, 4};
 int n = sizeof(arr)/sizeof(arr[0]);

 printf("Minimum cost of matrix-chain multiplication is: %d\n", MCMC_UsingDP(arr, 1, n-1));
 return 0;
}
