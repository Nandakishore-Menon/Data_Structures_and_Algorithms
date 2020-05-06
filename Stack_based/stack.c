//STACK IMPLEMENTATION USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
void push(struct node** top,int d)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    temp->prev=NULL;
    if(*top==NULL)
    {
        *top=temp;
    }
    else
    {
        (*top)->next=temp;
        temp->prev=*top;
        *top=temp;
    }
    
}
int pop(struct node** top)
{
    if((*top)->prev==NULL)
    {
        int d=(*top)->data;
        *top=NULL;
        return d;
    }
    struct node* ptr=*top;
    *top=ptr->prev;
    int d=ptr->data;
    //ptr->prev=NULL;
    (*top)->next=NULL;
    free(ptr);
    return d;
}
int main()
{
    //struct node* start=malloc(sizeof(struct node));
    struct node* top=NULL;
    //top=start;
    //top->prev=NULL;
    //top->next=NULL;
    int arr[]={5,4,3};
    push(&top,arr[0]);
    push(&top,arr[1]);
    push(&top,arr[2]);
    printf("%d->%d->%d",pop(&top),pop(&top),pop(&top));
}
