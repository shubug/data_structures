/*** Task is to find out if the given string is a rotation of the other string ***/
#include <stdio.h>
#include <string.h>

int checkIfExist(char temp[], char str){
 //Should use efficient Robin-Karp algo to find out if 'str' exist inside 'temp'
}

int checkIfRotation(char str1[], char str2[]){
 int len1, len2;
 len1 = strlen(str1);
 len2 = strlen(str2);

 if(len1 != len2)
  return 0; //As lengths aren't equal, it can't be the rotation of same string

 char *temp = (char *)malloc((len1*2 + 1)*sizeof(char));
 temp[0] = '\0';

 strcat(temp, str1);
 strcat(temp, str1);

 return checkIfExist(temp, str2);
}

int main(){
 char str1[] = "hubham";
 char str2[] = "hamhub";

 int res = checkIfRotation(str1, str2);
 return 0;
}
