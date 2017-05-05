#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int permExist(int ip1, int ip2, char *ip3, char *ip4){
 int i, x, j=0, k=0, count=0;
 int map[256] = {0};
 
 while(k <= ip2-ip1){ 
  //printf("\nEntering here again with character: %c\n", ip4[k]);
  
  for(i=0;i<ip1;i++)
    map[ip3[i]] = 0;

  for(i=0;i<ip1;i++)
   map[ip3[i]]++;
 
  for(i=k;i<ip2;){
   if(map[ip4[i]] == 0){
    //printf("Map count is 0 for character: %c\n", ip4[i]);
    //Need to restart checking as this character doesn't exist in smaller string
    k++;
    break;
   }
   else{
    //printf("\nEnetring outer else condition: ip4[%c]: %d\n", ip4[i], map[ip4[i]]);
    map[ip4[i]] = map[ip4[i]] - 1;
    i++;
    //Need to check here if the count of all characters in the map array is zero :| and if yes, increae the count by 1 count++
    for(x=0; x<256; x++){
     if(map[x] != 0)
      break;
    }
    //printf("Crossed the for loop after checking zero count with x: %d for %c\n", x, ip4[i-1]);
    if(x == 256){
     printf(" B I N G O one of the existed permutation is: ");
     for(int z=k; z<k+ip1; z++)
       printf("%c", ip4[z]);
     printf("\n");
     count++;
     k++;
     break;
    } 
   }
  }
 }
 return count;
}

int main(){
 int ip1, ip2, count;
 char *ip3, *ip4;

 ip3 = (char *)malloc(512000 * sizeof(char));
 ip4 = (char *)malloc(512000 * sizeof(char));

 printf("Enter length of 1st string: ");
 scanf("%d", &ip1);
 printf("Enter length of 2nd string: ");
 scanf("%d", &ip2);

 printf("Enter 1st string input: ");
 scanf("\n%[^\n]", ip3);
 printf("Enter 2nd string input: ");
 scanf("\n%[^\n]", ip4);

 count = permExist(ip1, ip2, ip3, ip4);
 printf("Number of perms exist in other string are: %d\n", count);

 return 0;
}
