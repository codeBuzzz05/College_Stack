#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char id[10];
    struct node *next;

}node;

typedef struct node * NODE;
NODE first=NULL;

void insert(){
NODE ptr,temp;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL){
    printf("Memory allocation failed\n");
    return ;
}
printf("Enter Bill id\n");
scanf("%s",temp->id);
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
printf("Added successfully\n");
}

void delete(){
    if(first==NULL){
        printf("Its empty!\n");
        return ;
    }
    NODE temp;
    temp=first;
    first=first->next;
     free(temp);
    printf("Bill processed Successfully\n");
}
void display(){
    NODE temp;
    temp=first;
    if(temp==NULL){
        printf("No bill to process\n");
        return ;
    }
    while(temp!=NULL){
        printf("Bill :%s",temp->id);
        temp=temp->next;
    }
}

int main(){
    int choice;
    while(1){
        printf("1.Add bill\n2.Process Bill\n3.Display\n4.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert();
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: exit(0);
        }
    }
    return 1;
}
