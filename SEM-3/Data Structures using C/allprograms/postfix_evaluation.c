#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int top=-1;
int stack[30];
int pop(){
    int x=stack[top];
    top--;
    return x;
}
void push(int ch){
    stack[++top]=ch;
}
void postfix_eval(char postfix[]){
    for(int i=0;postfix[i]!='\0';i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            push(ch-'0');
        }
        else{
            int op1=pop();
            int op2=pop();
            int result;
            switch(ch){
                case '^':result=op2^op1;
                break;
                case '/':result=op2^op1;
                break;
                case '*':result=op2^op1;
                break;
                case '+':result=op2^op1;
                break;
                case '-':result=op2^op1;
                break; 
            }
            push(result);
        }
    }
}

int main(){
    char postfix[50];
    printf("Enter a valid postfix expression\n");
    scanf("%s",postfix);
    postfix_eval(postfix);
    int result=stack[top];
    printf("Evaluation result : %d",result);
    return 1;
}