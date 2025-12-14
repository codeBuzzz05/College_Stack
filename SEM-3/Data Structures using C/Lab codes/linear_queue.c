#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int front;
int rear;
int *q;
int size=10;

void initialise(){
    q=(int *)malloc(size*sizeof(int));
    front=-1;
    rear=-1;
}

void enqueue(){
    if(rear==size-1){
        printf("The queue is full\n");
        return ;
    }
    int item;
    printf("Enter the customer number\n");
    scanf("%d",&item);
    if(rear==-1){
        front=0;
        rear=0;
        q[rear]=item;
    }
    else{
        q[++rear]=item;
    }
    printf("Number added to the queue\n");
}
void dequeue(){
    if(rear==-1){
        printf("The queue is empty\n");
        return ;
    }
    if(front==rear){
        front =-1;
        rear=-1;
    }
    else{
        front++;
    }
    printf("Element deleted successfully\n");
}

void display(){
    if(rear==-1){
        printf("Queue is empty\n");
        return ;
    }
    printf("Queue elements are:\n");
    for(int i=front;i<=rear;i++){
        printf("%d  ",q[i]);
    }
}

int main(){
    int choice;
    initialise();
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:enqueue();
            break;
            case 2: dequeue();
            break;
            case 3:display();
            break;
            case 4:
            free(q);
            exit(0);
        }
    }
    return 1;
}