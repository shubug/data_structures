/**** REVERSE ARRAY OR STRING ****/
#include <stdio.h>
#include <string.h>

int main()
{ char roll[] = "stumble tornadoes ";
  int len = strlen(roll);
  //printf("length of the string is %ld\n", strlen(roll));
  int l,r; 
  char temp;

  for(l=0,r=len-1;l<r;l++,r--){
  	temp = roll[l];
  	roll[l] = roll[r];
  	roll[r] = temp;
  } 
  printf("the new string is %s\n", roll);
  return 1;
}