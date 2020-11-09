 #include<stdio.h>
 #include<stdlib.h>
 struct node{
     int info;
     struct node *prev,*next;
 };
 struct node* start = NULL;
 void insertAsFirstNode(){
     struct node *n = (struct node*) malloc(sizeof(struct node));
     printf("Enter a Number: ");
     scanf("%d",&n->info);
     n->prev = NULL;
     n->next=NULL;
     if(start==NULL){
         start = n;
     }
     else{
         start->prev=n;
         n->next = start;
         start=n;
     }
 }

 void deleteFirstNode(){
     if(start==NULL){
         printf("List is empty");
     }
     else{
         struct node *r = start;
         start = start->next;
         start->prev=NULL;
         free(r);
     }
 }

 void traversal(){
     struct node *temp = start;
     if (start == NULL)
     {
         printf("Empty");
     }
     else{
         while(temp->next!=NULL){
             printf("%d",temp->info);
             temp = temp->next;
         }
     }
     
 }