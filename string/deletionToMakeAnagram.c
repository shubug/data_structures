#include <stdio.h>
#include <string.h>

char arr[26] = {0};

int calDeletions(char str1[], char str2[]){
 char *temp, *c, ch;
 int i, l1, l2, swaplen, res=0;
 l1 = strlen(str1);
 l2 = strlen(str2);
 
 if(l1 < l2){
  temp = str2;
  str2 = str1;
  str1 = temp;

  swaplen = l2;
  l2 = l1;
  l1 = swaplen;
 } 
 
 c = str1;
 while(*c != '\0'){
  ch = *c;
  arr[(ch-97)]++;
  c++;
 }
 
 c = str2;
 while(*c != '\0'){
  ch = *c;
  arr[(ch-97)]--;
  c++;
 }
 for(i=0; i<26; i++){ 
  if(arr[i] >= 0)
   res = res + arr[i];
  else
   res = res - arr[i];
 }
 return res;
}

int main(){
 char str1[10001];
 char str2[10001];
  
 scanf("%s", str1);
 scanf("%s", str2);
 
 printf("%d\n", calDeletions(str1, str2));
 return 0;
}
