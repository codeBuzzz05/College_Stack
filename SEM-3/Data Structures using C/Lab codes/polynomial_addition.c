#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node * next;
}node;

typedef struct node *NODE;
NODE createnode(int coeff,int exp){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Allocation failed\n");
        return NULL;
    }
    temp->coeff=coeff;
    temp->exp=exp;
    temp->next=NULL;
    return temp;
}

NODE insertnode(NODE head,int coeff,int exp){
    if(head==NULL){
        return createnode(coeff,exp);
    }
    NODE temp=createnode(coeff,exp);
    NODE curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}
void displaypoly(NODE head){
    if(head==NULL){
        printf("0\n");
        return ;
    }
    NODE temp=head;
    while(temp!=NULL){
        printf("%dx^%d",temp->coeff,temp->exp);
        if(temp->next!=NULL){
            printf(" + ");
        }
        temp=temp->next;
    }
    printf("\n");
}
NODE addpoly(NODE p1,NODE p2){
    NODE result =NULL;
    while(p1!=NULL&&p2!=NULL){
        if(p1->exp==p2->exp){
            result=insertnode(result,p1->coeff+p2->coeff,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->exp>p2->exp){
            result=insertnode(result,p1->coeff,p1->exp);
            p1=p1->next;
        }
        else if(p2->exp>p1->exp){
            result=insertnode(result,p2->coeff,p2->exp);
            p2=p2->next;
        }
    }
    while(p1!=NULL){
        result=insertnode(result,p1->coeff,p1->exp);
        p1=p1->next;
    }
    while(p2!=NULL){
        result=insertnode(result,p2->coeff,p2->exp);
        p2=p2->next;
    }
    return result;
}

NODE readpoly(NODE p){
    int coeff,exp;
    int n;
    printf("Enter number of terms\n");
    scanf("%d",&n);
    printf("Enter the coefficient and the exponent in the sorted order\n");
    for(int i=0;i<n;i++){
        printf("Enter term\n");
        scanf("%d %d",&coeff,&exp);
        p=insertnode(p,coeff,exp);
    }
    return p;
}

int main(){
    NODE p1,p2,res;
    p1=p2=res=NULL;
    int choice;
    printf("Ener polynomial 1\n");
    p1=readpoly(p1);
    printf("Enter polynomial 2\n");
    p2=readpoly(p2);
    displaypoly(p1);
    displaypoly(p2);
    res=addpoly(p1,p2);
    displaypoly(res);
    return 1;
    
}