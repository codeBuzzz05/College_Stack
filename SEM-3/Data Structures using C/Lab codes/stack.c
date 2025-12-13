#include<stdio.h>
#include<stdlib.h>

int size=10;
int ele;

typedef struct stack{
	int  *data;
	int top;
}stack;

void initialise(stack *p){
	p->top=-1;
	p->data=(int *)malloc(size*sizeof(int));
	if(!p->data){
		printf("Allocation failed!");
		exit(EXIT_FAILURE);
	}
}
void push(stack *p){
	if(p->top==size-1){
		printf("Overflow!!\n");
	}
	else{
		printf("Eneter the element to push\n");
		scanf("%d",&ele);
		p->data[++p->top]=ele;
		printf("Element %d pushed\n",ele);
	}
}
void pop(stack *p){
	if(p->top==-1){
		printf("The stack is empty!\n");
	}
	else{
		p->top-=1;
		printf("The element %d deleted!",p->data[p->top+1]);
	}
}
void display(stack *p){
	if(p->top==-1){
		printf("Stack is empty!\n");
	}
	else{
		for( int i=p->top;i>=0;i++){
			printf("%d\n",p->data[i]);
		}
	}
}

int main(){
	int choice=-1;
    stack q;
    initialise(&q);
    while(1){
        printf("-----------------------------------------------------------------\n");
        printf("1.push\n2.pop\n3.Display\n4.Quit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: push(&q);
            break;
            case 2: pop(&q);
            break;
            case 3:display(&q);
            break;
            case 4: 
            printf("Quited");
			free(q.data);
            return 0;
            default :printf("Invalid choice\n");
        }   
    }
    return 1;

}