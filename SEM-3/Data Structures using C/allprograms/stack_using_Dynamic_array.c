#include<stdio.h>
#include<stdlib.h>

int size;

typedef struct stack{
	int  *data;
	int top;
}stack;

void intitialise(stack *p){
	p->top=-1;
	p->data=(int *)malloc(size*sizeof(int));
	if(!p->data){
		printf("Allocation failed!");
		exit(EXIT_FAILURE);
	}
}
void push(stack *p, int ele){
	if(p->top==size-1){
		printf("Overflow!!\n");
	}
	else{
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
void isEmpty(stack *p){
	if(p->top==-1){
		printf("Yess it empty\n");
	}
	else{
		printf("Its not empty");
	}
}
void isFull(stack *p){
	if(p->top==size-1){
		printf("Stack is full\n");
	}
	else{
		printf("no its not full\n");
	}
}
void resize(stack *p,int n){
	p->data=(int *)realloc(p->data,n*sizeof(int));
		if(!p->data){
		printf("Allocation failed!");
		exit(EXIT_FAILURE);
	}
}

int main(){
	stack s;
	int n;
	printf("Enter the size of the stack\n");
	scanf("%d",&n);
	size=n;
	intitialise(&s);
	pop(&s);


	return 1;


}


