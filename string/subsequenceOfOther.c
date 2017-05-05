/*** Check if one given string is a subsequence of other string. In subsequence order of the characters matters but not the characters b/w them ***/
#include <stdio.h>
#include <string.h>

int isSubsequence(char str1[], int m, char str2[], int n){
 if(m == 0)
  return 1;
 if(n == 0)
  return 0;

 if(str2[n-1] == str1[m-1])
  return isSubsequence(str1, m-1, str2, n-1);
 else
  return isSubsequence(str1, m, str2, n-1);
}

int main(){
 char str1[] = "ARPAXY";
 char str2[] = "APAXYCPXY";
 int m, n;

 m = strlen(str1);
 n = strlen(str2);

 if(isSubsequence(str1, m, str2, n))
  printf("given string is a subsequence of the other string\n");
 else
  printf("not a subsequence of the other string\n");
 return 0;
}
