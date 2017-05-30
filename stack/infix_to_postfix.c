/*** Infix to postfix conversion using stack ***/
# include <stdio.h>
# include <stdlib.h>

char stack[20];
int top = 0; //Not starting with top=-1 b'coz we need to save space for the base mark i.e '('

void push(char data){
 stack[++top] = data;
}

char pop(){
 if (top == 0)
  return '(';
 return stack[top--];
}

int priority(char x){
 if(x == '(')
  return 0;
 if(x == '+' || x == '-')
  return 1;
 if(x == '*' || x == '/')
  return 2;
}

int main(){
 char exp[20];
 char *c;
 char x;
 printf("Enter the expression:: ");
 scanf("%s", exp);
 stack[0] = '('; //filling the bottom of the stack with base character
 c = exp;
 while(*c != '\0'){
  if(*c >= 48 && *c <= 57)
   printf("%c", *c);
  else if(*c == '('){
   push(*c);
  }
  else if(*c == ')'){
   x = pop();
   while(x != '(' ){
    printf("%c", x);
    x = pop();
   }
  }
  else{
   while(priority(stack[top]) >= priority(*c)){
    char temp = pop();
    printf("%c", temp);
   }
   push(*c);
  }
 c++;
 }
 while(top != 0)
  printf("%c", pop());
 return 0;
}
