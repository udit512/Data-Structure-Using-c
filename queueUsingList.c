#include<stdlib.h>
#include<stdio.h>
struct Queue{
    int data;
    struct Queue * next;
};
typedef struct Queue * ptr;
ptr front=NULL,rear=NULL;
void enQueue(){
    ptr q = (ptr)malloc(sizeof(struct Queue));
    printf("Enter the number");
    scanf("%d",&q->data);
    q->next = NULL;
    if (front == rear)
    {
        front = rear = q;
    }
    else
    {
        rear->next = q;
        rear = q;
    }
}
void deQueue(){
    if(front == NULL){
        printf("Empty Queue");
    }
    else{
    ptr q = front;
    front = front->next;
    free(q);
    }
}
void displayQueue(){
    //normal display like linked list traversing
}