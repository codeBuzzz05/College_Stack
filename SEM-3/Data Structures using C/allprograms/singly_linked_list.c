#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct node{
    char filename[20];
    int size;
    struct node *next;
}node;
typedef struct node * NODE;
NODE first=NULL;

void insert(){
    NODE temp,ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the filename\n");
    scanf("%s",temp->filename);
    printf("Enter file Size\n");
    scanf("%d",&temp->size);
    temp->next=NULL;
    if(first==NULL){
        first=temp;
    }
    else{
        ptr=first;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    printf("File inserted successfully!\n");
}
void delete(){
    char file[20];
    NODE temp,ptr;
    if(first==NULL){
        printf("List is empty\n");
        return ;
    }
    printf("Enter the filename to delete\n");
    scanf("%s",file);
    temp=first;
    if(strcmp(first->filename,file)==0){
        temp=first;
        first=first->next;
        free(temp);
    }
    else{
        while(temp!=NULL&&strcmp(temp->filename,file)!=0){
            ptr=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("File not found!\n");
            return ;
        }
        else{
            ptr->next=temp->next;
            free(temp);
        }
    }   
    printf("File deleted successfully\n"); 
    return ; 
}
void display(){
    NODE temp;
    temp=first;
    if(first==NULL){
        printf("Empty\n");
        return ;
    }
    printf("FILE DETAILS:\n");
    while(temp!=NULL){
        printf("File: %s  SIZE: %d\n",temp->filename,temp->size);
        temp=temp->next;
    }
}
int main(){
    int choice;
    while(1){
        printf("1.Insert\n2.Delete\n3.Display\n");
        printf("Enter a choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
        }
    }
    return 0;
}