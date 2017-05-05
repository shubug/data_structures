/*** Task is to reverse a string without using any temp variable ***/
#include <stdio.h>
#include <string.h>

//This method uses ASCII value difference between characters
void alterMethod(char str[], int start, int end){
 while(start<end){
  if(start > end){
   str[start] = str[end] - str[start];
   str[end] = str[end] - str[start];
   str[start] = str[start] + str[end];
  }
  else{
   str[start] = str[start] - str[end];
   str[end] = str[end] + str[start];
   str[start] = str[end] - str[start];
  }
 start++;
 end--;
 }
}

void reverse(char str[], int start, int end){
 while(start<end){
  str[start] ^= str[end];
  str[end] ^= str[start];
  str[start] ^= str[end];
  
  start++;
  end--;
 }
}

int main(){
 char str[] = "bonjour";
 int len = strlen(str);

 reverse(str, 0, len-1);
 alterMethod(str, 0, len-1);
 printf("Given string after reversal is: %s\n", str);
 return 0;
}
