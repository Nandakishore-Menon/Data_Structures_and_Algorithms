/*
Design a data structure which supports the following operations efficiently 
1)Add an integer x
2)delete an integer with maximum frequency - if there are more than one element with the same maximum frequency delete all of them.
*/
#include<stdio.h>
#include<stdlib.h>
struct hashnode
{
    int data;
    int count;
    struct hashnode* next;
    struct hashnode* prev;
    int heap;
};
struct heapnode
{
    int data;
    int count;
    struct hashnode* hash;
};

int hash(int num,int a, int b, int p,int c)
{
    return ((a*num+b)%p)%c;
}

void bottomup(int i,struct heapnode** H)
{
    int p=(i-1)/2;
    while((p>=0)&&(H[p]->count<H[i]->count))
    {
        (H[i]->hash)->heap=p;
        (H[p]->hash)->heap=i;
        struct heapnode* t=H[i];
        H[i]=H[p];
        H[p]=t;
        i=p;
        p=(i-1)/2;
    }
}
void topdown(int i,int n,struct heapnode** H)
{
    int l=0;
    while(2*i+2<n)
    {
        if(H[2*i+1]->count>H[2*i+2]->count)
        {
            l=2*i+1;
        }
        else
        {
            l=2*i+2;
        }
        if(H[i]->count<H[l]->count)
        {
            (H[i]->hash)->heap=l;
            (H[l]->hash)->heap=i;
            struct heapnode* t=H[i];
            H[i]=H[l];
            H[l]=t;
            i=l;
        }
        else break;
    }
    if((2*i+1<n)&&(H[i]->count<H[2*i+1]->count))
    {
        (H[i]->hash)->heap=2*i+1;
        (H[2*i+1]->hash)->heap=i;
        struct heapnode* t=H[i];
        H[i]=H[2*i+1];
        H[2*i+1]=t;
    }
}
int deletemax(int n,struct heapnode** H)
{
    
    int d=H[0]->data;
    struct heapnode* t=H[0];
    H[0]=H[n-1];
    H[n-1]=t;
    topdown(0,n-1,H);
    return d;
}

void add(struct hashnode** hashtable,struct heapnode** heap,int* h,int arr,int val)
{
    int flag=0;
    struct hashnode* temp=hashtable[val];
    if(hashtable[val]==NULL)
    {
        //printf("\ncase1 %d to be inserted\n",arr);
        
        hashtable[val]=malloc(sizeof(struct hashnode));
        struct hashnode* dum=malloc(sizeof(struct hashnode));
        hashtable[val]->next=dum;
        dum->prev=hashtable[val];
        dum->data=arr;
        
        dum->count=1;
        dum->next=NULL;
        dum->heap=*h;
        heap[*h]->count=1;
        heap[*h]->data=arr;
        
        heap[*h]->hash=dum;
        (*h)++;
    }
    else
    {
        
        while(temp->next!=NULL)
        {
            //printf("\ncase2 %d\n",arr);
            temp=temp->next;
            if(arr==temp->data)
            {
                (temp->count)++;flag=1;
                heap[temp->heap]->count=temp->count;
                bottomup(temp->heap,heap);
                break;
            }
            if(temp->next!=NULL)
                temp=temp->next;
            else
                break;
        }
        if(flag!=1)
        {
            //printf("\ncase3 %d\n",arr);
            struct hashnode* dum=malloc(sizeof(struct hashnode));
            temp->next=dum;
            dum->data=arr;
            dum->prev=temp;
            dum->count=1;
            dum->next=NULL;
            dum->heap=*h;
            heap[*h]->hash=dum;
            heap[*h]->data=arr;
            heap[*h]->count=1;
            (*h)++;
        }
    }
}


int main()
{
    int n;int d,m;
    scanf("%d",&n);d=n;
    scanf("%d",&m);
    int a,b,p;p=101;int c=2*n;
    a=(rand()%p)%c;
    b=(rand()%p)%c;
    
    int arr[n];int h=0;
    struct heapnode* heap[c];
    struct hashnode* hashtable[c];
    
    for(int i=0;i<c;i++)
    {
        heap[i]=malloc(sizeof(struct heapnode));
        hashtable[i]=NULL;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    for(int i=0;i<n;i++)
    {
        int val=hash(arr[i],a,b,p,c);
        add(hashtable,heap,&h,arr[i],val);
    }
    /*for(int g=0;g<h;g++)
    {
        printf("\nAt index %d is %d with count\n",g,heap[g]->data,heap[g]->count);
    }*/
    for(int j=0;j<m;j++)
    {
        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            int x;
            scanf("%d",&x);
            int val=hash(x,a,b,p,c);
            add(hashtable,heap,&h,x,val);
            //topdown(h-1,h,heap);
        }
        else
        {
            int max=heap[0]->count;
            while(heap[0]->count==max)
            {
                int val=hash(heap[0]->data,a,b,p,c);
                struct hashnode* delnode=heap[0]->hash;
                printf("Deleted: %d\n",deletemax(h,heap));
                (delnode->prev)->next=delnode->next;
                if(delnode->next)
                    (delnode->next)->prev=delnode->prev;
                else
                {
                    
                    free(hashtable[val]);
                    hashtable[val]=NULL;
                    //delnode->prev=NULL;
                    //free(delnode->prev);
                }
                free(delnode);
                
                h--;
            }
        }
        /*for(int g=0;g<h;g++)
        {
            printf("\nAt index %d is %d with count\n",g,heap[g]->data,heap[g]->count);
        }*/
    }
    
    return 0;
}

