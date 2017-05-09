/*** Task is to calculate the next greater number using the same digits in the number ***/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reverseANum(int n){
 int rem, temp, newNum = 0;
 while(n>0){
  rem = n % 10;
  newNum = (newNum*10) + rem;
  n = n/10;
 }
 return newNum;
}

int nextNum(int num){
 int i=0, rem, last, digit, dummy=0;
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
 printf("dummy: %d\n", dummy);
 
 if(found==0)
  return num;

 tens = (int)pow(10.0, i);
 temp = num/tens;
 printf("num: %d, temp: %d\n", num, temp);
 left = temp/10;
 digit = temp % 10;
 right = num % tens;
 
 swap_digit = right % 10;
 right = (right/10)*10 + digit;
 right = reverseANum(right);
 
 printf("left: %d, right: %d, swap_digit: %d, i: %d, temp: %d, num: %d\n", left, right, swap_digit, i, temp, num);
 return ((left*10)+swap_digit)*tens + right;
}

int main(){
 //int num = 218765;
 int num = 534976;
 printf("The next greater number with the same digits is: %d\n", nextNum(num));
 return 0;
}
