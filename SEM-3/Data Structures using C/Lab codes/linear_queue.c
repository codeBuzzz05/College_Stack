#include<stdio.h>
#include<stdlib.h>

int size=10;
struct q{
  int *data;
  int front,rear;
};
typedef struct q queue;

void initialise(queue* q){
  q->data=(int *)malloc(size*sizeof(int));
  q->rear=-1;
  q->front=-1;
}

void enqueue(queue* q){
 if(q->rear==size-1){
    printf("Overflow\n");
    return ;
  }
  int data;
  printf("Enter the data\n");
  scanf("%d",&data);
  if(q->rear==-1){
    q->front=0;
    q->rear=0;
    q->data[q->rear]=data;
  }
  else{
    q->rear=(q->rear+1);
    q->data[q->rear]=data;
  }
  printf("%d inserted to the queue\n",data);
}
void dequeue(queue* q){
  if(q->rear==-1){
    printf("Underflow\n");
    return ;
  }
  if(q->rear==q->front){
    q->rear=q->front=-1;
  }
  else{
    q->front=(q->front+1);
  }
  printf("Deletion successful\n");
}
void display(queue* q){
  if(q->rear==-1){
    printf("Empty!\n");
    return ;
  }
  int i=q->front;
  while(i<=q->rear){
    printf("%d  ",q->data[i]);
    i+=1;
  }
  printf("\nDisplay successful\n");
}

int main(){
  int choice;
  queue q;
  initialise(&q);
  while(1){
    printf("\n1.enqueue\n2.dequeue\n3.display\n4.quit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
      case 1: enqueue(&q);
              break;
      case 2: dequeue(&q);
              break;
      case 3: display(&q);
              break;
      case 4: exit(0);
    }
  }
  return 0;
}