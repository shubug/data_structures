#include <stdio.h>
#include <string.h>

int main(){
 int i, j, n, k;
 char str[100001];
 int arr[100001] = {0};

 scanf("%d %d", &n, &k);
 scanf("%s", str);
 
 i = n/2 - 1;
 if(n%2 == 0)
  j = n/2;
 else
  j = i + 2;

 if(k > 0){
  while(j<n && i>=0){
   if(str[j]-'0' > str[i]-'0'){
    str[i] = str[j];
    if(arr[i] == 0){
     k--;
     arr[i] = 1;
    }
   }
   else if(str[j]-'0' < str[i]-'0'){
    str[j] = str[i];
    if(arr[j] == 0){
     k--;
     arr[j] = 1;
    }
   }
   else{}
   i--;
   j++;
  
   if(k == 0){
    while((str[i] == str[j]) && j<n){
     i--;
     j++; 
    }
    if(j==n){
     printf("%s\n", str);
     return 1;
    }
    else{
     printf("-1\n");
     return -1;
    }
   }
    
  }
  i = 0;
  j = n-1;
  while(k>=1 && i<j){
   if(arr[i]==1 || arr[j]==1){
    if(str[i] != '9'){ 
     str[i] = str[j] = '9';
     k--;
    }
   }
   else{
    if(k == 1)
     break;
    if(str[i] != '9'){
     str[i] = '9';
     if(arr[i] == 0){
      k--;
      arr[i] = 1;
     }
     str[j] = '9';
     if(arr[j] == 0){
      k--;
      arr[j] = 1;
     }
    }
   }
   i++;
   j--;
  }
  
  if(k>0 && n%2!=0)
   str[n/2] = '9';
  printf("%s\n", str);
 }
 else{
  while(i>=0 && j<n){
   if(str[i] != str[j]){
    printf("-1\n");
    return -1;
   }
   i--;
   j++; 
  }
  if(j==n)
   printf("%s\n", str);  
 } 
 return 0;
}
