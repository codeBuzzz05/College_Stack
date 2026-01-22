#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node{
  char filename[20];
  int size;
  struct node* prev;
  struct node* next;
};

typedef struct node* NODE;

NODE head=NULL;

void insert(){
  NODE temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter the file name\n");
  if(temp==NULL){
    printf("Memory allocation for the file falied\n");
    return ;
  }
  scanf("%s",temp->filename);
  temp->prev=NULL;
  temp->next=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
  printf("New file %s added at the front\n",head->filename);

  }
void delete(){
  if(head==NULL){
    printf("No files to delete\n");
    return ;
  }
  NODE curr=head;
  int loc;
  int count=0;
  printf("Enter the deleting file's position\n");
  scanf("%d",&loc);
  while(curr!=NULL){
    count+=1;
    if(count==loc){
      break;
    }
    curr=curr->next;
  }
  if(curr==NULL){
    printf("Invalid position\n");
    return ;
  }
  if(curr==head){
    if(curr->next==NULL){
      free(head);
      head=NULL;
    }
    else{
      head=curr->next;
      head->prev=NULL;
      free(curr);
    }
  }
else if(curr->next ==NULL){
    curr->prev->next=NULL;
    free(free);
    }
  else{
    curr->prev->next=curr->next;
    curr->next->prev=curr->prev;
    free(curr);
  }
  printf("File deleted\n");
}
void display(){
  if(head==NULL){
    printf("No files to display\n");
    return ;
  }
  NODE curr=head;
  while(curr!=NULL){
    int l=strlen(curr->filename);
    printf("%s size:%d | ",curr->filename,l);
    curr=curr->next;
  }
  printf("\n");
}

int main(){
  int choice;
  while(1){
    printf("1.Add File\n2.Delete File\n3.Display Files\n");
    printf("Enter you Choice\n");
    scanf("%d",&choice);
    switch (choice){
      case 1: insert();
              break;
      case 2: delete();
              break;
      case 3: display();
              break;
      case 4: printf("Quited\n");
              exit(0);
    }
  }
  return 0;
}