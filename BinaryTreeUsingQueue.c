#include<stdlib.h>
#include<stdio.h>
#include "QueueForTree.h"
void preOrder(struct TreeNode * p){
    if(p){
        printf("%d",(p)->data);
        preOrder(((p)->leftChild));
        preOrder(((p)->rightChild));
    }
}

void createTree(struct TreeNode ** root){
    struct Queue *front=NULL ,*rear=NULL ;
    struct TreeNode * p, * t;
    printf("Enter the root Element : ");
    int x;
    scanf("%d",&x);
    *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*root)->data = x;
    (*root)->rightChild = (*root)->leftChild = NULL;
    printf("%d",(*root)->data);
    enqueue(*root,&front,&rear);
    while(!isEmpty(front,rear)){
        p = dequqe(&front,&rear);
        printf("\nEnter Left Child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t->data = x;
            t->rightChild = t->leftChild = NULL;
            p->leftChild = t;
            enqueue(t,&front,&rear);
        }
        printf("\nEnter Right Child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t->data = x;
            t->rightChild = t->leftChild = NULL;
            p->rightChild = t;
            enqueue(t,&front,&rear);
        }
    }
    
    
}

void main(){
    struct TreeNode * root = NULL;
    createTree(&root);
    printf("%d",root->data);
    preOrder(root);
}