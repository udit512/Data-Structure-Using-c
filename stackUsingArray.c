#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int capacity;
    int *array;
};

struct Stack * createStack(int cap){
    struct Stack * stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top= -1;
    stack->capacity = cap;
    int *array = (int *)malloc(cap*sizeof(int));
    stack->array = array;
    return stack;
}
int isFull(struct Stack * stack){
    if(stack->top == stack->capacity-1){
        return 1;
    }
    else return 0;
}
int isEmpty(struct Stack * stack){
    if(stack->top==-1)
        return 1;
    else
        return 0;
}
void push(struct Stack * stack){
    int data;
    printf("Enter the number : ");
    scanf("%d",&data);
    if(isFull(stack))
        printf("Stack Full || Stack Overflow");
    else{
        stack->top++;
        stack->array[stack->top]= data;
        printf("Inserted Element");
    }
}
void pop(struct Stack * stack){
    if (!isEmpty(stack))
    {
        stack->top--;
    }
    else{
        printf("Empty Stack || stack underflow");
    }
    
}
void display(struct Stack * stack){
    if (!isEmpty(stack))
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d\t",stack->array[i]);
    }
    else{
        printf("Stack Empty");
    }
}
void main(){
    int ch;
    int cap;
    printf("Enter Capacity of Stack: ");
    scanf("%d",&cap);
    struct Stack * stack = createStack(cap);
    while (1)
    {
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    push(stack);
                    break;
            case 2:
                    pop(stack);
                    break;
            case 3:
                    display(stack);
                    break;
            case 4:
                    exit(0);
            default:
                printf("Invalid Option");
        }
    }
}
