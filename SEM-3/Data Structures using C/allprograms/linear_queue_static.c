#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define size 5

typedef struct queue{
    int *data;
    int rear;
    int front;
}queue;

void initialise(queue *q){
    q->front=-1;
    q->rear=-1;
    q->data=(int *)malloc(size*sizeof(int));
}

void enqueue(queue *q){
    int item;
    if(q->rear==size-1){
        printf("Queue overflow\n");
        return ;
    }
    printf("Enter the element to push\n");
    scanf("%d",&item);
    if(q->front==-1){
        q->front=0;
        q->rear=0;
        q->data[q->rear]=item;  
    }
    else{
        q->data[++q->rear]=item;
    }
    printf("element pushed\n");
}
void dequeue(queue *q){
    
    if(q->front==-1){
        printf("queue is empty!\n");
        return ;
    }
    else if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;

    }
    else{
        q->front++;
    }
    printf("Deletion Successfull\n");
}
void display(queue *q){
    if(q->front==-1){
        printf("Queue is empty\n");
        return ;
    }
    printf("Queue elements are:\n");
    for(int i=q->rear;i>=q->front;i--){
        printf("%d\n",q->data[i]);
    }
}
int main(){
    int choice=-1;
    queue q;
    initialise(&q);
    while(1){
        printf("-----------------------------------------------------------------\n");
        printf("1.Enqueue\n2.dequeue\n3.Display\n4.Quit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue(&q);
            break;
            case 2: dequeue(&q);
            break;
            case 3:display(&q);
            break;
            case 4: 
            printf("Quited");
            return 0;
            default :printf("Invalid choice\n");
        }   
    }
    return 1;
}
