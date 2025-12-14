#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char filename[20];
    int size;
    struct node * prev;
    struct node *next;
}node;

typedef struct node * NODE;
NODE first=NULL;

void insert(){
    NODE temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory allocation failed\n");
        return ;
    }
    printf("Enter filename\n");
    scanf("%s",temp->filename);
    printf("Enter the size\n");
    scanf("%d",&temp->size);
    temp->prev=NULL;
    temp->next=NULL;

    if(first==NULL){
        first=temp;
    }
    else{
        temp->next=first;
        first->prev=temp;
        temp->prev=NULL;
        first=temp;
    }
    printf("Inserted to the front successfully.\n");
}
void delete(){
    int pos;
    NODE temp;
    int count=1;
    temp=first;
    printf("position\n");
    scanf("%d",&pos);
    if(first==NULL){
        printf("List is empty\n");
        return ;
    }
    if(pos==1){
        if(first->next==NULL){
            free(first);
            first=NULL;
            return ;
        }
        temp=first;
        first=first->next;
        first->prev=NULL;
        free(temp);
        return ;
    }
    while(temp!=NULL&&count<pos){
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        printf("Invalid position\n");
        return ;
    }
    if(temp->next==NULL){
        temp->prev->next=NULL;
        free(temp);
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
}
void display(){
    NODE temp;
    temp=first;
    if(temp==NULL){
        printf("Empty\n");
        return ;
    }
    while(temp!=NULL){
        printf("File: %s  SIZE: %d\n",temp->filename,temp->size);
        temp=temp->next;
    }
}
int main(){
    int choice;
    while(1){
        printf("1.Add File\n2.Delete File\n3.Display\n4.Quit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4: return 1;
        }
    }
    return 1;
}
