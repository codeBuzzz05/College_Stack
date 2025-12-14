#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct node{
    int id;
    struct node * next;
}node;
typedef struct node* NODE;
NODE rear=NULL;

void enqueue(){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Allocation failed\n");
        return ;
    }
    printf("Enter customer id\n");
    scanf("%d",&temp->id);
    if(rear==NULL){
        rear=temp;
        rear->next=rear;
    }
    else{
        temp->next=rear->next;
        rear->next=temp;
        rear=temp;
    }
    printf("Inserted at the rear end\n");
    return ;
}
void dequeue(){
    if(rear==NULL){
        printf("Queue is empty\n");
        return ;
    }
    NODE front=rear->next;
    if(front==rear){
        rear=NULL;
        free(front);
    }
    else{
        rear->next=front->next;
        free(front);
    }
    printf("Element deleted from the frontend\n");
    return ;
}
void display(){
    if(rear==NULL){
        printf("Empty!\n");
    }
    else{
        NODE temp=rear->next;
    while(1){
        printf("Customer id:%d\n",temp->id);
        if(temp->next==rear->next)
            break;
        temp=temp->next;
    }
}
return ;
}

int main(){
    int choice;
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3:display();
            break;
            case 4: exit(0);
        }
    }
    return 1;
}


