#include<stdlib.h>
#include<stdio.h>

struct TreeNode{
    int data;
    struct TreeNode * leftChild;
    struct TreeNode * rightChild;
};

struct Queue{
    struct TreeNode * Q;
    struct Queue * next; 
};

void enqueue(struct TreeNode * Q,struct Queue ** front,struct Queue ** rear){
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
    t->Q = Q;
    t->next = NULL;
    if(*front == NULL){
        *front = *rear = t;
        printf("Inserted element");
    }
    else{
        (*rear)->next = t;
        *rear = t;
        printf("Inserted element");
    }
    
}
struct TreeNode * dequqe(struct Queue ** front,struct Queue ** rear){
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
    if(front==NULL){
        printf("Queue is empty");
        return NULL;
    }
    else
    {
        t = *front;
        *front = (*front)->next;
        struct TreeNode * q = t->Q;
        free(t);
        return q;
    } 
}
void display(struct Queue * front,struct Queue * rear){
    if(front == NULL){
        printf("Queue is empty");
    }
    else{
        struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
        t = front;
        while(t!=NULL){
            printf("%p", t->Q);
            t = t->next;
        }
    }
}

int isEmpty(struct Queue * front,struct Queue * rear){
    return front == rear && front==NULL;
}