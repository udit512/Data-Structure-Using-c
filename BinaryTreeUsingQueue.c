#include<stdlib.h>
#include<stdio.h>
#include "QueueForTree.h"
void main(){
    struct Queue *front=NULL ,*rear=NULL ;
    struct TreeNode * t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    t->leftChild=t->rightChild=NULL;
    enqueue(t,&front,&rear);
    enqueue(t,&front,&rear);
    enqueue(t,&front,&rear);
    enqueue(t,&front,&rear);
    enqueue(t,&front,&rear);
    enqueue(t,&front,&rear);
    
    display(front,rear);
}