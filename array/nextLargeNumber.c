/*** Task is to calculate the next greater number using the same digits in the number ***/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reverseANumWithDigit(int n, int *digit){
 int rem, found=0, temp, newNum = 0;
 while(n>0){
  rem = n % 10;
  if(found==0 && (rem > *digit)){
   temp = *digit;
   *digit = rem;
   rem = temp;
   found = 1;
  }
  newNum = (newNum*10) + rem;
  n = n/10;
 }
 return newNum;
}

int nextNum(int num){
 int i=0, rem, last, dummy=0;
 int tens, temp, left, right, swap_digit, found=0;
 
 if(num <= 10)
  return num;
 
 dummy = num;
 last = dummy % 10;
 dummy = dummy/10;

 for(i=1; dummy>0;i++){
  rem = dummy % 10;
  if(rem < last){
   found=1;
   break;
  }
  last = rem;
  dummy = dummy/10;
 }
 
 if(found==0)
  return num;
 
 int *digit = (int *)malloc(sizeof(int));
 
 tens = (int)pow(10.0, i);
 temp = num/tens;
 left = temp/10;
 *digit = temp % 10;
 right = num % tens;
 
 swap_digit = right % 10;
 right = reverseANumWithDigit(right, digit);
 
 return ((left*10)+(*digit))*tens + right;
}

int main(){
 //int num = 218765;
 int num = 537986;
 //int num = 534976;
 printf("The next greater number with the same digits is: %d\n", nextNum(num));
 return 0;
}
