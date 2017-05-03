/*** To check if given 2 strings are isomorphic or not ***/
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

int isIso(char *str1, int m, char *str2, int n){
 int marked[MAX_CHARS] = {0};
 int map[MAX_CHARS];
 
 if(m != n)
  return 0;
 memset(map, -1, sizeof(map));

 for(int i=0; i<m; i++){
  if(map[str1[i]] == -1){
  	if(marked[str2[i]] != 0)
  	 return 0;

    marked[str2[i]] = 1;
    map[str1[i]] = str2[i];
  } 
  else{
  	if(map[str1[i]] != str2[i])
  	 return 0;
  }
 }

 return 1;
}

int main(){
 char str1[] = "aabaabcab";
 char str2[] = "xxyxxyxxy";

 int m = sizeof(str1)/sizeof(str1[0]);
 int n = sizeof(str2)/sizeof(str2[0]);

 int res = isIso(str1, m, str2, n);
 if(res == 1)
 	printf("Strings are Isomorphic\n");
 else
 	printf("Non-Isomorphic strings");
 return 0;
}
