#include <stdio.h>

int main(){
 int x, y, h, n;
 int remainder, res=0;
 
 printf("Enter value of x and y:\n");
 scanf("%d", &x);
 scanf("%d", &y);

 printf("Enter height of wall:\n");
 scanf("%d", &h);

 if(h < x){
  printf("Number of jumps required is 1\n");
  return 1;  
 }

 res = (h-x) / (x-y);
 remainder = (h-x) % (x-y);

 if (remainder > 0)
  res = res + 2; // 1 is added to take the last jump and 1 is added to cover the remainder part with one jump
 else
  res = res + 1; //This one is added just to take the last jump without any slipping

 printf("Number of jumps required are: %d\n", res); 
 return 0;
}
