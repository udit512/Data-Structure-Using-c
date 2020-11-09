#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front,rear;
    int capacity;
    int *array;
};
typedef struct Queue * ptr;
ptr createQueue(int Capacity){
    ptr q = (ptr)malloc(sizeof(struct Queue));
    q->capacity = Capacity;
    q->front=q->rear=-1;
    q->array = (int *)malloc(Capacity*sizeof(int));
    return q;
}
int isEmpty(ptr q){
    if(q->front == -1){
        return 1;
    }
    return 0;
}
int isFull(ptr q){
    if((q->rear+1)%q->capacity == q->front){
        return 1;
    }
    return 0;
}
void enQueue(ptr q){
    if(!isFull(q)){
        int data;
        printf("Enter Number :");
        scanf("%d",&data);
        q->rear = (q->rear+1)%q->capacity;
        q->array[q->rear]=data;
        if(q->front == -1){
            q->front = q->rear;
        }
    }else{
        printf("Queue is Full || Overflow");
    }
}
void deQueue(ptr q){
    if(!isEmpty(q)){
        if(q->front==q->rear)
            q->front=q->rear=-1;
        else
            q->front = (q->front+1)%q->capacity;
    }
    else{
        printf("Underflow");
    }
}
void deleteQueue(ptr q){
    if(q){
        if(q->array){
            free(q->array);
        }
        free(q);
    }
}
void displayQueue(ptr q){
    int temp = q->front;
    if(temp>q->rear){
    while(temp!=q->rear){
        printf("%d\t",q->array[temp]);
        temp = (temp+1)%q->capacity;
    }
    printf("%d",q->array[q->rear]);
    }
    else
        for(;temp<=q->rear;temp++)
            printf("%d\t",q->array[temp]);
}

void main(){
    int ch;
    printf("enter Capacity");
    int cap;
    scanf("%d",&cap);
    ptr queue = createQueue(cap);
    while (1)
    {
        printf("Enter ur choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    enQueue(queue);
                    break;
            case 2:
                    deQueue(queue);
                    break;
            case 3:
                    displayQueue(queue);
                    break;
            case 4:
                    deleteQueue(queue);
                    break;
            case 5:
                    exit(0);
            default:
                    printf("invalid Choice");
        }
    }
    
    
}