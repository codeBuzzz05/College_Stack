#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
int n;

typedef struct queue{
    int *data;
    int front;
    int rear;
    int curr_size;
}queue;

void initialise(queue *q ){
    q->curr_size=0;
    q->front=0;
    q->rear=0;
    q->data=(int *)malloc(n*sizeof(int));
}

void enqueue(queue *q){
    int item;
    if(q->curr_size==n){
        printf("Its Full\n");
        return ;
    }
    printf("Enter the element to insert\n");
    scanf("%d",&item);
    if(q->curr_size==0){
        q->data[q->rear]=item;
        q->curr_size+=1;
    }
    else{
        q->data[++(q->rear)]=item;
        q->curr_size+=1;
    }
}
void dequeue(queue *q){
    if(q->curr_size==0){
        printf("Its already empty\n");
    }
    else{
        q->front=(q->front+1)%n;
        q->curr_size-=1;
    }
}
void display(queue *q){
    while(q->curr_size!=0){
        printf("%d",q->data[q->front]);
        q->curr_size-=1;
        q->front=(q->front+1)%n;
    }
}
int main(){
    queue q;
    initialise(&q);
   int choice=-1;
   printf("Enter the size of the array\n");
   scanf("%d",&n);
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
            return 1;
            default :printf("Invalid choice\n");
        }   
    }
}