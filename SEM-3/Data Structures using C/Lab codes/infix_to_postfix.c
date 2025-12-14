#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[30];
int top=-1;
int precedence(char x){
    switch(x){
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-': return 1;
        default :return -1;
    }
}

void infixtopostfix(char infix[],char postfix[]){
    int k=0;
    for(int i=0;infix[i]!='\0';i++){
        char ch=infix[i];
        if(isalnum(ch)){
            postfix[k++]=ch;
        }
        else if(ch=='('){
            stack[++top]=ch;
        }
        else if(ch==')'){
            while(stack[top]!='('){
                postfix[k++]=stack[top--];
            }
            top--;
        }
        else{
            while(precedence(stack[top])>precedence(ch)){
                postfix[k++]=stack[top--];
            }
            stack[++top]=ch;
        }
    }
    while(top!=-1){
        postfix[k++]=stack[top--];
    }
    postfix[k]='\0';
}

int main(){
    char infix[30];
    char postfix[30];
    printf("Enter a valid infix expression\n");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("The eqvivalent postfix expression is : %s",postfix);
    return 1;
}