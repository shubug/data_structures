#include <stdio.h>
#include <string.h>

int evenSub(char str[]){
 int len = strlen(str);
 int temp, count = 0;

 for(int i=0; i<len; i++){
  temp = str[i] - '0';
  if(temp % 2 == 0)
   count = count + (i+1);
 }
 return count;
}

int main(){
 char str[] = "12347";
 
 printf("No. of even substrings are: %d\n", evenSub(str));
 return 0;
}
