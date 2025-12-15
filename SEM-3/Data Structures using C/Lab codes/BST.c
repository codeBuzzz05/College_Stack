#include<stdio.h>
#include<stdlib.h>

struct node {
    int id;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE;

NODE create(int id) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->id = id;
    temp->left = temp->right = NULL;
    return temp;
}

NODE insert(NODE root, int id) {
    if(root == NULL)
        return create(id);

    if(id < root->id)
        root->left = insert(root->left, id);
    else if(id > root->id)
        root->right = insert(root->right, id);

    return root;
}

void preorder(NODE root){
    if(root == NULL)
        return;
    printf("%d ", root->id);
    preorder(root->left);
    preorder(root->right);
}

void largest(NODE root){
    if(root == NULL){
        printf("Database is empty\n");
        return;
    }
    NODE temp = root;
    while(temp->right != NULL)
        temp = temp->right;
    printf("Largest: %d\n", temp->id);
}

int main(){
    NODE root = NULL;
    int choice, id;

    while(1){
        printf("\n--- Hospital CT Image Indexing System (BST) ---\n");
        printf("1. Insert Image ID\n");
        printf("2. Display Image IDs (Preorder Traversal)\n");
        printf("3. Display Largest Image ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Image ID: ");
                scanf("%d", &id);
                root = insert(root, id);
                break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                largest(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
