# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int stack[20];
int top = -1;

void push(int x){
 stack[++top] = x;
}

int pop(){
 if(top == -1)
  return INT_MIN; //Using this as End of stack number
 return stack[top--];
}

int calPostfix(char exp[]){
 char *c = exp;
 int val1, val2, res;
 while(*c != '\0'){
  if(*c >= 48 && *c <= 57){
   push((*c)-'0');
  }
  else{
   val1 = pop();
   val2 = pop();
   if(*c == '+')
    res = val1 + val2;
   else if(*c == '-')
    res = val1 - val2;
   else if(*c == '*')
    res = val1 * val2;
   else
    res = val1 / val2;
   
   push(res);
  }
 c++; 
 }
 return pop();
}

int main(){
 char exp[20];
 printf("Enter the postfix expression: ");
 scanf("%s", exp);

 printf("%d\n", calPostfix(exp));
 return 0;
}
