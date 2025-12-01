#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char stack[30];
int top=-1;
int precedence(char x){
    switch(x){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return -1;
        }
 }
void infixtopostfix(char infix[],char postfix[]){
    int k=0;
    for(int i=0;infix[i]!='\0';i++){
        char symbol=infix[i];
        if(isalnum(symbol)){
            postfix[k++]=symbol;
        }
        else if(symbol=='('){
            stack[++top]=symbol;
        }
        else if(symbol==')'){
            while(stack[top]!='('){
                postfix[k++]=stack[top--];
            }
            top--;
        }
        else{
            while (precedence(stack[top])>=precedence(symbol)){
                postfix[k++]=stack[top--];
            }
            stack[++top]=symbol;
        }
              
    }
    while(top!=-1){
        postfix[k++]=stack[top--];
    }
    postfix[k]='\0';
}

void main(){
     char infix[30];
     char postfix[30];
     printf("Enter a valid infix expression :\n");
     scanf("%s",infix);
     infixtopostfix(infix,postfix);
     printf("Equivalent post fix expression is : %s",postfix);
}