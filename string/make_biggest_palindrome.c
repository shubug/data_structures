/*** Make biggest palidrome string from the given string with the fixed number of changes <= k ***/
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
  while(j<n && i>=0){ //Changes in this while loop are neccessary to make the resultant string a palindrome if it is already not
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
  
   if(k == 0){ //To check if after changing some characters we are short of any more changes,  then just check if remaining corresponding characters are matching or not
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
  //At this point,  string is already palindrome but we are left with more changes (k>0) so we will try to convert remaining characters in '9' as much as we can
  i = 0;
  j = n-1;
  while(k>=1 && i<j){
   if(arr[i]==1 || arr[j]==1){//to make both corresponding chars '9',but we have already touched/changed one of them, so no need to decrement 'k' (no need to count it as new change)
    if(str[i] != '9'){ 
     str[i] = str[j] = '9';
     k--;
    }
   }
   else{
    if(k == 1) //only one change is left, but to make the string bigger we need atleast 2 changes k>=2
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
  
  if(k>0 && n%2!=0) //if k=1 so and string has odd length , we try to change middle character as '9'
   str[n/2] = '9';
  printf("%s\n", str);
 }
 else{ //If number of changes allowed are 0, then just check if the corresponding characters are matching than string is already palindrome ,return it as it is, else return -1 
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
