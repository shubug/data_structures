/*** Task is to convert one string into another usin =g minimum number of insert/delete/replace oprations ***/
/*** Complexity of the approach below is 3 raise to the power m , where 3 is for (insert + delete + replace) and 'm' is length of the bigger string worst casehappens when no character int the strings matches ***/
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c){
 if(a<b)
  return a<c?a:c;
 else
  return b<c?b:c;
}

int editDistance(char str1[], int m, char str2[], int n){
 if(m == 0 || n == 0)
  return m>0?m:n;
 else{
  if(str1[m-1] == str2[n-1])
   return editDistance(str1, m-1, str2, n-1);
  else
   return 1+min(editDistance(str1, m, str2, n-1), editDistance(str1, m-1, str2, n), editDistance(str1, m-1, str2, n-1));
 }
}

int editDistanceUsingDP(char str1[], int m, char str2[], int n){
 if(m == 0 || n == 0)
  return m>0?m:n;

 int arr[n+1][m+1];
 int i, j;

 for(i=0; i<=n; i++)
  arr[i][0] = i;
 for(j=1; j<=m; j++)
  arr[0][j] = j;
 
 for(i=1; i<=n; i++){
  for(j=1; j<=m; j++){
   if(str1[j-1] == str2[i-1])
    arr[i][j] = arr[i-1][j-1];
   else
    arr[i][j] = 1 + min(arr[i-1][j-1], arr[i-1][j], arr[i][j-1]);
  }
 }

 return arr[i-1][j-1];
}

int main(){
 char str1[] = "sunday";
 char str2[] = "saturday";
 int m = strlen(str1);
 int n = strlen(str2);
 
 printf("Edit distance: %d\n", editDistanceUsingDP(str1, m, str2, n));
 return 0;
}
