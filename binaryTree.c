#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* leftBranch;
    struct node* rightBranch;
};

struct node* newNode(int data)
{
struct node* node;
node = (struct node*) malloc(sizeof(struct node));
    if(node == NULL)
    {
        printf("Node Pointer is a NULL:\n");
        exit(1);
    }
    else{
        printf("Its Not a Null Pointer\n");
    }
    node->data = data;
    
    node->leftBranch  = NULL;
    node->rightBranch = NULL;
    
    return(node);
}

void preOrderTraversal(struct node* root){
    if(root != NULL)
    {
        printf("%d-", root->data);
        preOrderTraversal(root->leftBranch);
        preOrderTraversal(root->rightBranch);
    }
}

void inOrderTraversal(struct node* root){
    if(root != NULL)
    {
        inOrderTraversal(root->leftBranch);
        printf("%d-", root->data);
        inOrderTraversal(root->rightBranch);
        //preOrderTraversal(root->rightBranch);
    }
}

void postOrderTraversal(struct node* root){
    if(root != NULL)
    {
        postOrderTraversal(root->leftBranch);
        postOrderTraversal(root->rightBranch);
        printf("%d-", root->data);
        //preOrderTraversal(root->rightBranch);
    }
}

void levelOrderTraversal(struct node* root, int i){
    if(root != NULL)
    {
        if(i == 1)
        {
            printf("%d-", root->data);
        }
        else if(i > 1)
        {
            i--;
            levelOrderTraversal(root->leftBranch, i);
            levelOrderTraversal(root->rightBranch, i);
        }
    }
}

int main(){
    struct node* root = newNode(1);
    root->leftBranch  = newNode(2);
    root->rightBranch = newNode(3);
    
    root->leftBranch->leftBranch    = newNode(4);
    root->leftBranch->rightBranch   = newNode(5);

    root->rightBranch->leftBranch   = newNode(6);
    root->rightBranch->rightBranch  = newNode(7);

    //root->leftBranch->leftBranch->rightBranch  = newNode(8);
    preOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    for(int i = 1; i<=3; i++)
    {
        levelOrderTraversal(root, i);
    }

    printf("\n\n");
    return 0;
}

