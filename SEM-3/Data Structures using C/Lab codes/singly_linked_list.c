#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};
typedef struct node* NODE;

NODE head=NULL;

void insert(){
  NODE temp=(struct node*)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("Allocation failed\n");
    return ;
  }
  int key;
  printf("Enter the customer Bill ID\n");
  scanf("%d",&key);
  temp->data=key;
  temp->next=NULL;
  NODE curr=head;
  if(curr==NULL){
    head=temp;
  }else{
    while(curr->next!=NULL){
      curr=curr->next;
    }
    curr->next=temp;
  }
}

void deletion(){
  if(head==NULL){
    printf("Empty \n");
    return ;
  }
if(head->next==NULL){
  free(head);
  head=NULL;
}
else{
  NODE temp=head;
  head=head->next;
  free(temp);
}
printf("Deletion from the front successful\n");
}
void display(){
  if(head==NULL){
    printf("Empty\n");
    return ;
  }
  NODE curr=head;
  while(curr!=NULL){
    printf("Bill  Id : %d  ",curr->data);
    curr=curr->next;
  }
  printf("\nSuccessfully Displayed\n");
}

int main(){
    int choice;
    while(1){
        printf("1.Add bill\n2.Process Bill\n3.Display\n4.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
          case 1 : insert();
                   break;
          case 2: deletion();
                  break;
          case 3: display();
                  break;
          case 4: exit(0);
        }
    }
    return 0;

}