#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int data;
    struct Stack * next;
};
typedef struct Stack * stackptr;
void push(stackptr top){
    stackptr q = (stackptr)malloc(sizeof(struct Stack));
    if (q == NULL)
    {
        printf("Stack OverFlow");
    }
    else{
        printf("Enter the number ");
        scanf("%d",&q->data);
        if(top != NULL){
        q->next = top;
        top = q;
        }
        else{
            q->next = NULL;
            top = q;
        }
        printf("Element iserted in Stack");
    }
}
void pop(stackptr top){
    stackptr q = (stackptr)malloc(sizeof(struct Stack));
    if(top!=NULL){
        q = top;
        top = q->next;
        free(q);
        printf("Item Deleted");
    }
    else
    printf("Stack UnderFlow");
}
void display(stackptr top){
    stackptr q = (stackptr)malloc(sizeof(struct Stack));
    if(top!=NULL){
        q = top;
        while(q!=NULL){
            printf("%d\t",q->data);
            q=q->next;
        }
    }
    else{
        printf("Empty Stack");
    }
}

void main(){
    stackptr TOP = NULL;
    while(1)  
    {  
        int ch;
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&ch);  
        switch(ch)  
        {  
            case 1:  
            {   
                push(TOP);  
                break;  
            }  
            case 2:  
            {  
                pop(TOP);  
                break;  
            }  
            case 3:  
            {  
                display(TOP);  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                exit(0);
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    }
}  
}