/*** Equal_Point is an index such that the number of opening brackets before it is equal to the number of closing brackets from and after ***/
#include <stdio.h>

int findEqualPoint(char *str){
 //1.Simply take a temp array of string length.
 //2.Traverse it from left to right storing the number of opening braces.
 //3.Traverse it from right to left reducing the count in temp array for every closing brace.
 //4.If the count hits zero, that's the equal index point.	

 return 1;
}

int alterMethod(char *str){
 int len = sizeof(str)/sizeof(str[0]);
 printf("length = %d\n", len);
 int count = 0, val = 0;

 for(int i=0; i<len-1; i++){
   if(str[i] == '('){
   	count++;
   	str[i] = count;
   	printf("value of count is %d\n", count);
   	val++;
   }
 }

 for(int i=0; i<len-1; i++){
 	printf("%c ", str[i]);
 }
 printf("\n");

 count = 0;
 for(int i=len-2; i>0; i--){
   if(str[i] == ')'){
   	count++;
   	if(val == count)
   	 return i;
   }
   else if(str[i] != ')' && str[i] != '('){
   	val--;
   }
 }
 return -1;
}

int main(){
 //char str[] = "(())))(";
 char str[] = "()))()(()";
 int index, len = sizeof(str)/sizeof(str[0]);

 //index = findEqualPoint(str);
 index = alterMethod(str); //Without using any extra space

 if (index != -1)
  printf("The equal point index is: %d ", index);
 else
  printf("There isn't any equal point index in this string\n");

 return 0;
}
