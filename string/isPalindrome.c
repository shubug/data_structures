#include <stdio.h>
#include <string.h>

int isPal(char str[], int s, int e){
 if(s == e)
  return 1;
 
 if(str[s] != str[e])
  return 0;

 if(s+1 < e) //To ensure that there are more than 2 characters in the remaining substring
  return isPal(str, s+1, e-1);
}

int isPalindrome(char str[]){
 int len = strlen(str);
 if (len == 0)
  return 1;
 
 return isPal(str, 0, len-1);
}

int main(){
 char str[] = "malaayalam";

 int res = isPalindrome(str);
 
 if(res == 0)
  printf("Given string is not palindrome\n");
 else
  printf("Above string is a palindrome string\n");
 return 0;
}
