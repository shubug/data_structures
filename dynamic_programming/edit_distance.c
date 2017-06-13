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

int main(){
 char str1[] = "sunday";
 char str2[] = "saturday";
 int m = strlen(str1);
 int n = strlen(str2);
 
 printf("Edit distance: %d\n", editDistance(str1, m, str2, n));
 return 0;
}
