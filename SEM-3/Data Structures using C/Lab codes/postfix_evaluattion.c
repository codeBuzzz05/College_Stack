#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
int top=-1;
int stack[30];

int pop(){
    return stack[top--];
}
void push(int ele){
    stack[++top]=ele;
}

void postfix_evaluate(char postfix[]){
    for(int i=0;postfix[i]!='\0';i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            push(ch-'0');
        }
        else{
            char op=ch;
            int op1=pop();
            int op2=pop();
            int result;
            switch(op){
                case '+':result=op2+op1;
                        push(result);
                        break;
                case '-': result=op2-op1;
                        push(result);
                        break;
                case '*': result=op2*op1;
                        push(result);
                        break;
                case '/': result=op2/op1;
                        push(result);
                        break;
                case '^': result=op2^op1;
                        push(result);
                        break;
                default: printf("Invalid operator\n");
                              exit(0);
            }
        }
    }
}

int main(){
    char postfix[30];
    printf("Enter a valid postfic expression \n");
    scanf("%s",postfix);
    postfix_evaluate(postfix);
    printf("The final result is :%d",stack[top]);
    return 1;
}