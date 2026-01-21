#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};
typedef struct node* NODE;

NODE create(int key){
  NODE temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("Dynamic allocation failed\n");
    return NULL;
  }
  temp->data=key;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

NODE insert(NODE root,int key){
  if(root==NULL){
    return create(key);
  }
  NODE temp=create(key);
  NODE curr=root;
  NODE parent=NULL;
  while(curr!=NULL){
    parent=curr;
    if(key>curr->data){
      curr=curr->right;
    }
    else{
      curr=curr->left;
    }
  }
  if(key>parent->data){
    parent->right=temp;
  }
  else{
    parent->left=temp;
  }
  return root;
}

void preorder(NODE root){
  if(root==NULL){
    return ;
  }
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
void largest(NODE root){
  if(!root){
    return ;
  }
  while(root->right!=NULL){
    root=root->right;
  }
  printf("\nLargest is %d",root->data);
}

int main(){
  int choice,key;
  NODE root=NULL;
  while(1){
    printf("\n1.insert\n2.preorder\n3.Largest\n4.Quit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
      case 1 : 
        printf("Enter CT image ID");
        scanf("%d",&key);
        root=insert(root,key);
        printf("Successfull\n");
        break;
      case 2: preorder(root);
              break;
      case 3:
              largest(root);
              break;
      case 4: exit(0);
      default : printf("Invalid case\n");
                exit(0);
    }
}
return 0;
}

