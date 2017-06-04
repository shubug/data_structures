/*** Task is to find out the number of changes in first string to make it an anagram of the second string ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int arr[26] = {0};

int numOfChanges(char str[], int len){
 int i;
 char *c;
 c = str
 
 for(i=0; i<len/2; i++, c++){
  arr[(*c)-'a']++;
  
 c++;
 while(*c != '\0'){
 } 

 return 0;
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
  
 return 1;
}
