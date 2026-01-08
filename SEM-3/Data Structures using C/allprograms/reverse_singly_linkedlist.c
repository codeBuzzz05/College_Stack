#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}node;
typedef struct node * NODE;
NODE head=NULL;
void reverse(NODE head){
    if(head ==NULL){
        return NULL;
    }
    NODE curr,prev,next;
    curr=head;
    prev=NULL;
    next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        curr=prev;
        prev=next;
    }
    head=prev;
}