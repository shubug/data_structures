/*** Task is to find out the number of changes in first string to make it an anagram of the second string ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int numOfChanges(char str[], int len){
 int arr[26] = {0};
 int i, res=0;
 char *c;
 c = str;
 
 for(i=0; i<len/2; i++, c++)
  arr[(*c)-'a']++;
 
 while(*c != '\0'){
  arr[(*c)-'a']--;
  c++;
 } 

 for(i=0; i<26; i++){
  if(arr[i] > 0)
   res = res + arr[i];
  else
   res = res - arr[i];
 }

 return res/2;
}

int main(){
 char str[10001];
 int len, count;

 scanf("%d", &count);
 while(count > 0){
  scanf("%s", str);
  len = strlen(str);
  if(len%2 != 0)
   printf("%d\n", -1);
  else
   printf("%d\n", numOfChanges(str, len));
  count--;
 }
  
 return 0;
}
