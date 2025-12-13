#include<stdio.h>
#include <stdlib.h>
int size=10;
typedef struct queue{
    int front;
    int rear;
    int *data;
}queue;

void initialise(queue * q){
    q->front=-1;
    q->rear=-1;
    q->data=(int *)malloc(size*sizeof(int));
    if(q->data==NULL){
        printf("Dynamic allocation failed\n");
        exit(0);
    }
}

void enqueue(queue *q){
    if(q->rear==size-1){
        printf("Queue is full\n");
        return ;
    }
    int item;
    printf("Enter the element to insert\n");
    scanf("%d",&item);
    if(q->front==-1){
        q->front=0;
        q->rear=0;
        q->data[q->rear]=item;
        printf("The elemented added to the queue\n");
    }
    else{
        q->data[++q->rear]=item;
        printf("The elemented added to the queue\n");
        return ;
    }
   
}

void dequeue(queue *q){
    if(q->rear==-1){
        printf("queue is already empty\n");
        return ;
    }
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        int x=q->data[q->front];
        q->front+=1;
        printf("The element %d deleted successfully\n",x);
        return ;
    }
}
void display(queue * q){
    if(q->rear==-1){
        printf("The queue is empty!\n");
        return ;
    }
    printf("Queue elements are :\n");
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->data[i]);
    }
    printf("\n");
}

int main(){
    queue q;
    initialise(&q);
    int choice;
    while(1){
            printf("1.Enque\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:enqueue(&q);
        break;
    case 2:dequeue(&q);
        break;
    case 3:display(&q);
        break;
    case 4:printf("Exiting the pogram\n");
        exit(0);
    
    default:printf("Invalid choice\n");
    }
    }
    return 1;

}