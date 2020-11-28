#include<stdlib.h>
#include<stdio.h>
#include "QueueForTree.h"

struct TreeNode * createTree(int rootVal){
    struct TreeNode * tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    tree->data = rootVal;
    tree->leftChild=tree->rightChild = NULL;
    return tree;
}

void insertNode(struct TreeNode ** node,int leftVal,int rightVal){
    struct TreeNode *l,*r;
    l = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    r = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (leftVal == -1){
        l = NULL;
    }
    if (rightVal == -1)
    {
       r = NULL;
    }
    
    l->data = leftVal;
    l->leftChild = l->rightChild = NULL;
    r->data = leftVal;
    r->leftChild = r->rightChild = NULL;
    (*node)->leftChild = l;
    (*node)->rightChild = r;
}


void main(){
    printf("Enter the root element: ");
    int data;
    scanf("%d",&data);
    struct TreeNode *root = createTree(data);
    struct TreeNode * t,*left,*right;
    struct Queue *front=NULL ,*rear=NULL ;
    enqueue(root,&front,&rear);
    while (!isEmpty(front,rear))
    {
        t = dequqe(&front,&rear);
        printf("Enter the left child 0f -> %d",t->data);
        int l ;scanf("%d",&l);
        printf("Enter the right child 0f -> %d",t->data);
        int r ;scanf("%d",&r);
        if (l != -1){
            left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            left->data = l;
            left->leftChild = left->rightChild = NULL;
            enqueue(left,&front,&rear);

        }else{
            left = NULL;
        }
        if (r != -1)
        {
            right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            right->data = r;
            right->leftChild = left->rightChild = NULL;
            enqueue(right,&front,&rear);
        }
        else
        {
            right = NULL;
        }
    }    
    printf("root->%d",root->leftChild->data);
}