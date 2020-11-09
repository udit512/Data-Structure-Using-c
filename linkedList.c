#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *START = NULL;

struct node* createNode(){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
}

void insertNode(){
    struct node* temp;
    temp = createNode();
    int info;
    printf("Enter info: ");
    scanf("%d",&info);
    temp->info = info;
    temp->link = NULL;
    if(START == NULL){
        START=temp;
    }
    else{
        struct node* temp1 = START;
        while(temp1->link!=NULL)
            temp1=temp1->link;
        temp1->link = temp;
    }
}

void deleteNode(){
    struct node *r;
    if(START==NULL){
        printf("List Is Empty");
    }
    else{
        r =START;
        START = r->link;
        free(r);
    }
}

void traversing(){
    if(START == NULL){
        printf("List is Empty");
    }
    else{
    struct node* temp = START;
    while (temp !=NULL)
    {
        printf("Info = %d",temp->info);
        temp = temp->link;
    }
    }
}



void main(){
    while(1){
        int ch;
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    insertNode();
                    break;
            case 2:
                    deleteNode();
                    break;
            case 3:
                    traversing();
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                printf("Invalid Choice");
        }
        
    }
}
