#include<stdio.h>
#include<stdlib.h>
int size=10;
struct node{
  int* data;
  int top;
};
typedef struct node stack;

void initialise(stack* s){
  s->data=(int*)malloc(size*sizeof(int));
  if(s->data==NULL){
    printf("Allocation failed\n");
    return ;
  }
  s->top=-1;
}

void push(stack* s){
  if(s->top==size-1){
    printf("Overflow\n");
    return ;
  }
  int item;
  printf("enter the webpage number\n");
  scanf("%d",&item);
  s->data[++s->top]=item;
  printf("New tab opened successfully\n");
}

void pop(stack* s){
  if(s->top==-1){
    printf("No active tabs\n");
    return ;
  }
  s->top-=1;
  printf("The current tab closed\n");
}
void display(stack* s){
  if(s->top==-1){
    printf("No opened tabs\n");
    return ;
  }
  printf("All the active pages:\n");
  for(int i=s->top;i>=0;i--){
    printf("Web page no:%d\n",s->data[i]);
  }
  printf("\n");
}
int main(){
  int choice;
  stack s;
  initialise(&s);
  while(1){
    printf("\n1.Open new page\n2.close recent tab\n3.Display all active tabs\n4.Quit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
      case 1: push(&s);
              break;
      case 2: pop(&s);
              break;
      case 3: display(&s);
              break;
      case 4: exit(0);
    }

  }
  return 0;
}