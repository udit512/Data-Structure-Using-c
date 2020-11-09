#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int flag;
    struct node *next;
};
typedef struct node * nodeptr;
nodeptr  getNode(int data){
    nodeptr q = (nodeptr)malloc(sizeof(struct node));
    q->data = data;
    q->flag =0;
    return q;
}
void deleteNode(nodeptr p){
    if (p==p->next || p==NULL)
    {
        printf("List is empty.Cant Delete");
    }
    else{
        nodeptr q;
        q=p->next;
        p->next = q->next;
        free(q);
    }
}
void insertNode(nodeptr p){
    nodeptr q;
    printf("enter number to insert");
    int data;
    scanf("%d",&data);
    q = getNode(data);
    q->next = p->next;
    p->next = q;
}
void displayNodes(nodeptr p){
    if(p==p->next){
        printf("List Empty");
    }
    else{
        nodeptr q = p->next;
        do
        {
            printf("data = %d",q->data);
            q = q->next;
        } while (q->flag!=1);
    }
}
void main(){
    nodeptr header = (nodeptr)malloc(sizeof(struct node));
    header->next = header;
    header->flag = 1;
    header->data = -1;
    int ch;
    while (1)
    {
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    insertNode(header);
                    break;
            case 2:
                    deleteNode(header);
                    break;
            case 3:
                    displayNodes(header);
                    break;
            case 4:
                    exit(0);
            default:
                printf("Invalid Option");
        }
    }
    
}
