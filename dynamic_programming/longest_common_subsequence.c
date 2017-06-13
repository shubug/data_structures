/*** Task is to find the longest common subsequence in given 2 strings ***/
/*** For strings below LCS is abcf (length 4) ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
 return a>b?a:b;
}

int LCS(char str1[], char str2[]){
 char c = 'f';
 int l1 = strlen(str1);
 int l2 = strlen(str2);
 int arr[l2+1][l1+1];
 int i, j, res;

 for(i=0; i<=l2; i++)
  arr[i][0] = 0;
 for(j=1; j<=l1; j++)
  arr[0][j] = 0;

 for(i=1; i<=l2; i++){
  for(j=1; j<=l1; j++){
   if(str1[j-1] == str2[i-1])
    arr[i][j] = arr[i-1][j-1] + 1;
   else
    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
  }
 }
 res = arr[i-1][j-1];
 /*** Additional code to print the LCS ***/
 /*** This will print the LCS in reverse order. For correct order keep pushing the characters in a stack and the pop n print them until the stack is empty ***/
 i = i-1;
 j = j-1;
 while(i>0 && j>0){
  if(str1[j-1] == str2[i-1]){
   printf("%c ", str1[j-1]);
   i--;
   j--;
  }
  else{
   if(arr[i-1][j] > arr[i][j-1])
    i--;
   else
    j--;
  }
 }
 printf("\n");
 return res;
}

int main(){
 char str1[] = "abcdaf";
 char str2[] = "acbcf";

 printf("Longest Common Subsequence is: %d\n", LCS(str1, str2));
 return 0;
}
