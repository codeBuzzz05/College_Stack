#include<stdio.h>
#include<stdlib.h>

struct node{
  int coeff;
  int exp;
  struct node* next;
};
typedef struct node* NODE;

NODE create(int coeff,int exp){
  NODE temp=(struct node*)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("Memory allocation failed\n");
    return NULL;
  }
  temp->coeff=coeff;
  temp->exp=exp;
  temp->next=NULL;
  return temp;
}

NODE insert(NODE head,int coeff,int exp){
  if(head==NULL){
    return create(coeff,exp);
  }
  NODE curr=head;
  NODE temp=create(coeff,exp);
  while(curr->next!=NULL){
    curr=curr->next;
  }
  curr->next=temp;
  return head;
}

NODE addpoly(NODE p1,NODE p2,NODE res){
  while(p1!=NULL&&p2!=NULL){
    if(p1->exp==p2->exp){
      res=insert(res,(p1->coeff+p2->coeff),p1->exp);
      p1=p1->next;
      p2=p2->next;
    }
    else if(p1->exp>p2->exp){
      res=insert(res,p1->coeff,p1->exp);
      p1=p1->next;
    }
    else{
      res=insert(res,p2->coeff,p2->exp);
      p2=p2->next;
    }
  }
  while(p1!=NULL){
    res=insert(res,p1->coeff,p1->exp);
    p1=p1->next;
  }
  while(p2!=NULL){
    res=insert(res,p2->coeff,p2->exp);
    p2=p2->next;
  }
  return res;
}
void display(NODE head){
  if(head==NULL){
    printf("0\n");
  }
    NODE curr=head;
    while(curr!=NULL){
      printf("%dx^%d",curr->coeff,curr->exp);
      if(curr->next!=NULL){
        printf("+");
      }
      curr=curr->next;
    }
    printf("\n");
}

int main(){
  int n,coeff,exp;
  NODE p1,p2,res;
  p1=p2=res=NULL;
  int choice;
  while(1){
    printf("\n1.insertpoly\n2.Addpoly\n3.displaypoly\n4.quit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch (choice){
      case 1: printf("Enter the number of terms in the p1\n");
              scanf("%d",&n);
              printf("Enter coeff and expo in the decreasing order\n");
              for(int i=0;i<n;i++){
                scanf("%d %d",&coeff,&exp);
                p1=insert(p1,coeff,exp);
              }
              printf("Enter the number of terms in the p2");
              scanf("%d",&n);
              printf("Enter coeff and exxp in the decreasing order\n");
              for(int i=0;i<n;i++){
                scanf("%d %d",&coeff,&exp);
                p2=insert(p2,coeff,exp);
              }
              break;
      case 2: res=addpoly(p1,p2,res);
              printf("Result\n");
              display(res);
              break;
      case 3: printf("P1:\n");
              display(p1);
              printf("\nP2\n");
              display(p2);
              printf("\n");
              break;
      case 4: exit(0);
    }
  }
  return 0;
}