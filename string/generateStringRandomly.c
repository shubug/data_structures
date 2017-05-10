/*** Program to generate a string randomly ***/
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
 int i, len;
 char *str, ch;
 
 printf("Enter the length of the unexisted string\n");
 scanf("%d", &len);

 str = (char *)malloc(len * sizeof(char));
 srand(time(NULL));

 for(i=0; i<len; i++){
  *(str+i) = (char)(((rand() % 26)+97) - '\0');
 }
 str[len] = '\0';
 printf("Randomly generated string is: %s\n", str);
 return 0;
}
