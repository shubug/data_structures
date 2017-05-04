/*** Print all permutaions of a string ***/
/*** Complexity = n! * n where n! is the no. of output strings and n is the string length to print the entire string everytime ***/
/*** If we just have to count the no. of total permutations of the string instead of printing them , then complexity would be just n! not n! * n

#include <stdio.h>
#include <string.h>

int count = 0;

void swap(char *a, char *b, int back){
 char temp = *a;

 if(back == 1)
  printf("Swapped back %c -> %c\n", *a, *b);
 else
  printf("Swapped .... %c -> %c\n", *a, *b);

 *a = *b;
 *b = temp;
}

void printAllPerm(char str[], int l, int r){
 if(l == r){
  count++;
  printf("%d: %s\n", count, str);
 }
 else{
  for(int i=l; i<=r; i++){
   swap(str+l, str+i, 0);
   printAllPerm(str, l+1, r);
   swap(str+l, str+i, 1);
  }
 }
}

int main(){
 char str[] = "ABCD";
 int len = strlen(str);
 printAllPerm(str, 0, len-1);

 return 0;
}
