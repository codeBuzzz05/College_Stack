#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char url[50];
    struct node* next;
};
typedef struct node* NODE;
struct stack{
    struct node* top;

};
typedef struct stack* STACK;

void initialise(STACK s){
    s->top=NULL;
}

void push(STACK s,char url[]){
NODE new=(NODE)malloc(sizeof(struct node));
new->next=s->top;
s->top=new;
strcpy(new->url,url);
}

int pop(STACK s, char poppedurl[]){
    if(s->top==NULL){
        return 0;
    }
    NODE del=s->top;
    s->top=del->next;
    strcpy(poppedurl,del->url);
    free(del);
    return 1;
}

void clearstack(STACK s){
    char dummy[50];
    while(pop(s,dummy));
}
void display(char currentpage[]){
    printf("Current page: %s\n",currentpage);
}

void visitnew(STACK backward,STACK forward, char currentpage[]){
    char newurl[50];
    printf("Enter new url\n");
    scanf("%s",newurl);
    push(backward,currentpage);
    clearstack(forward);
    strcpy(currentpage,newurl);
    printf("Visited to the new page :%s\n",currentpage);
}

void goback(STACK backward,STACK forward,char currentpage[]){
    char prevurl[50];
    if(pop(backward,prevurl)==0){
        return ;
    }
    push(forward,currentpage);
    strcpy(currentpage,prevurl);
    printf("Moved back : %s\n",currentpage);
}

void goforward(STACK backward,STACK forward,char currentpage[]){
    char next[50];
    if(pop(forward,next)==0){
        return ;
    }
    push(backward,currentpage);
    strcpy(currentpage,next);
    printf("Moved forward: %s\n",currentpage);
}

int main(){
    struct stack forward,backward;
    int choice;
    char currentpage[50]="HOME";
    initialise(&forward);
    initialise(&backward);
    while(1){
        printf("\n1.Visit new page\n2.gobackward\n3.move forward\n4.show current page\n5.quit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : visitnew(&backward,&forward,currentpage);
            break;
            case 2 : goback(&backward,&forward,currentpage);
            break;
            case 3 : goforward(&backward,&forward,currentpage);
            break;
            case 4: display(currentpage);
            break;

            case 5: exit(0);
        }
    }
    return 0;
}

