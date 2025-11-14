#include <stdio.h>
#include <stdlib.h>
#define size 10
int choice;
int top=-1;
int stack[size];
int main(){
    void push();
    void pop();
    void display();

    int condition=1;
    while(condition){
        printf("Enter any one number to perform the operation\n");
        printf("1.push\n2.pop\n3.display\n4.quit\n");
        if(scanf("%d",&choice)!=1){
            printf("Invalid choice!\n");
             while(getchar() != '\n'); 
        }
        else{
            switch (choice){
                case 1: push();
                    break;
                case 2: pop();
                    break;
                case 3: display();
                break;
                case 4: condition=0;
                printf("End of program\n");
                    break;
                default: printf("Invalid choice!\n");
                break;
        }
    }
}
return 0;
}
void pop(){
    if(top==-1){
        printf("Stack is Empty!\n");
    }
    else{
        top-=1;
        printf("Element %d deleted successfully\n",stack[top+1]);
            
    }
}
void push(){
    int ele;
    if(top==size-1){
        printf("Stack overflow!\n");
    }
    else{
        printf("Enter the element to push\n");
        scanf("%d",&stack[++top]);
    }
}
void display(){
    if(top==-1){
        printf("Stack is empty!\n");
    }
    else{
        printf("Number of elements in the stack: %d\n",(top+1));
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
        
    }
}