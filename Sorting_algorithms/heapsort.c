#include<stdio.h>
void bottomup(int i,int* H)
{
    int p=(i-1)/2;
    while((p>=0)&&(H[p]<H[i]))
    {
        int t=H[i];
        H[i]=H[p];
        H[p]=t;
        i=p;
        p=(i-1)/2;
    }
}
void topdown(int i,int n,int* H)
{
    int l=0;
    while(2*i+2<n)
    {
        if(H[2*i+1]>H[2*i+2])
        {
            l=2*i+1;
        }
        else
        {
            l=2*i+2;
        }
        if(H[i]<H[l])
        {
            int t=H[i];
            H[i]=H[l];
            H[l]=t;
            i=l;
        }
        else break;
    }
    if((2*i+1<n)&&(H[i]<H[2*i+1]))
    {
        int t=H[i];
        H[i]=H[2*i+1];
        H[2*i+1]=t;
    }
}
void add(int x,int n,int* H)
{
    H[n]=x;
    bottomup(n,H);
}
int deletemax(int n,int* H)
{
    
    int d=H[0];
    H[0]=H[n-1];
    topdown(0,n-1,H);
    return d;
}
void buildheap(int n,int* H)
{
    for(int i=n/2;i>=0;i--)
    {
        topdown(i,n,H);
    }
}
int main()
{
    int n;int d;
    scanf("%d",&n);d=n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    buildheap(n,arr);int dum;
    for(int i=0;i<d;i++)
    {
        dum=deletemax(n,arr);
        n--;
        arr[n]=dum;
    }
    for(int i=0;i<d;i++)
    {
        printf("%d ",arr[i]);
    }
}

