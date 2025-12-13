#include<stdio.h>
#include<stdlib.h>

int size=10;
typedef struct cqueue{
    int front;
    int rear;
    int *data;
}cqueue;

void initialise(cqueue *q){
    q->front=-1;
    q->rear=-1;
    q->data=(int *)malloc(size*sizeof(int));
    if(q->data==NULL){
        printf("Error in memory allocation\n");
        exit(0);
    }
}
void enqueue(cqueue *q){
    if((q->rear+1)%size==q->front){
        printf("Its Full!\n");
        return ;
    }
    int item;
    printf("Enter the item\n");
    scanf("%d",&item);
    if(q->rear==-1){
        q->rear=0;
        q->front=0;
        q->data[q->rear]=item;
    }
    else{
        q->rear=(q->rear+1)%size;
        q->data[q->rear]=item;
    }
    printf("Element added successfully!\n");
}
void dequeue(cqueue *q){
    if(q->rear==-1){
        printf("Already empty\n");
        return  ;
    }
    if(q->front==q->rear){
        q->rear=-1;
        q->front=-1;
    }
    else{
        q->front=(q->front+1)%size;
    }
    printf("element deleted successfully!\n");
}
void display(cqueue *q){
    if(q->rear==-1){
        printf("Queue is empty\n");
        return ;
    }
    int i=q->front;
    printf("Queue elements are:\n");
    while(1){
        printf("%d  ",q->data[i]);
        if(i==q->rear){
            break;
        }
        i=(i+1)%size;
    }
    printf("\n");

}
int main(){
    int choice;
    cqueue q;
    initialise(&q);
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue(&q);
                    break;
            case 2:dequeue(&q);
                    break;
            case 3:display(&q);
                    break;
            case 4:printf("Exiting\n");
                    free(q.data);
                    exit(0);
            default:printf("Invalid choice\n");
        }
    }
    return 1;
}