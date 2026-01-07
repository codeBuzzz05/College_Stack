#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * left;
    struct node * right;
    int key;
}node;
typedef struct node * NODE;
NODE insert_node(NODE root, int key){
    NODE temp = (NODE)malloc(sizeof(struct node ));
    if(temp==NULL){
        printf("dynamic allocation failed \n");
        return NULL;
    }
    temp->key=key;
    temp->left=temp->right=NULL;
    NODE curr = root;
    NODE parent =NULL;
    if(curr==NULL){
        return temp;
    }
    while(curr!=NULL){
        parent=curr;
        if(key>curr->key){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    if(key>parent->key){
        parent->right=temp;
    }
    else{
        parent->left=temp;
    }
    return root;
    
}
void inorder(NODE root){
    if(root==NULL)
    return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}
void preorder(NODE root){
    if(root==NULL)
    return ;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(NODE root){
    if(root==NULL)
    return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key); 
}
void peek(NODE root){
    if(root->right==NULL){
        printf("MAX element is %d\n",root->key);
        return ;
    }
    peek(root->right);
}
void search(NODE root,int key){
    if(root==NULL){
        printf("Sorry not found \n");
        return ;
    }
    if(key==root->key){
        printf("Yes its there\n");
        return ;
    }
    if(key<root->key){
        search(root->left,key);
    }
    else{
        search(root->right,key);
    }
}

int main(){
    NODE root=NULL;
    int choice=0;
    int item,key;
    while(1){
        printf("\n1.Insert\n2.Inorder\n3.preorder\n4.postorder\n5.Exit\n");
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element\n");
                    scanf("%d",&item);
                    root=insert_node(root,item);
                    printf("Inserted successfully\n");
                    break;
            case 2: inorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 5 : peek(root);
                    break;
            case 6:printf("Enter searching element\n");
                   scanf("%d",&key); 
                   search(root,key);
            case 7: exit(1);
        }
    }
    return 1;
}