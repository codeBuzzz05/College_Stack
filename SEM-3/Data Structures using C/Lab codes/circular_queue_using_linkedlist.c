#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};
typedef struct node* NODE;

NODE rear=NULL;

void enqueue(){
  int key;
  NODE temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("Sorry the heap is Full\n");
    return ;
  }
  printf("Enter the customer ID\n");
  scanf("%d",&key);
  temp->data=key;
  temp->link=NULL;
  if(rear==NULL){
    rear=temp;
    rear->link=rear;
  }
  else{
    temp->link=rear->link;
    rear->link=temp;
    rear=temp;
  }
  printf("customer %d added to the queue\n",key);
}

void dequeue(){
  if(rear==NULL){
    printf("No customers to serve\n");
    return ;
  }
  int key=rear->link->data;
  if(rear->link==rear){
    free(rear);
    rear=NULL;
  }
  else{
    NODE temp=rear->link;
    rear->link=temp->link;
    free(temp);
  }
  printf("%d Served\n",key);
}
void display(){
  if(rear==NULL){
    printf("No customers in Queue\n");
    return ;
  }
  NODE curr=rear->link;
  printf("The customers in Queue \n");
  while(1){
    printf("customer id : %d  ",curr->data);
    curr=curr->link;
    if(curr==rear->link)
      break;
  }
  printf("\n");
}

int main(){
  int choice;
  while(1){
    printf("1.Insert\n2.Delete\n3.Display\n4.Quit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
      case 1 : enqueue();
               break;
      case 2 : dequeue();
               break;
      case 3 : display();
               break;
      case 4 : printf("Quited\n");
               exit(0);
    }
  }
}