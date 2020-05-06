//This is an implementation of segment trees with a few queries like Range Minimum query,Next right minimum etc
#include<stdio.h>

void build(int* A,int* st,int n)
{
	for(int i=0;i<n;i++)
	{
        st[n+i-1]=i;
	}
    for(int i=n-2;i>=0;i--)
    {
        if(A[st[2*i+1]]>A[st[2*i+2]])
        {
            st[i]=st[2*i+2];
        }
        else
        {
            st[i]=st[2*i+1];
        }
    }
}
void update(int* A,int* st,int x,int i,int n)
{
    A[i]=x;
    i=(n-1+i-1)/2;
    while(i>=0)
    {
        if(A[st[2*i+1]]>A[st[2*i+2]])
        {
            st[i]=st[2*i+2];
        }
        else
        {
            st[i]=st[2*i+1];
        }
        i=(i-1)/2;
    }
        
}
int RMQ(int* st,int* a,int i,int j,int s,int e,int n,int p)
{
    if((j<s)||(i>e))
    {
        return n;
    }
    if((i<=s) && (e<=j))
    {
        return st[p];
    }
    int m=(s+e)/2;
    int l1=RMQ(st,a,i,j,s,m,n,2*p+1);
    int l2=RMQ(st,a,i,j,m+1,e,n,2*p+2);
    if(a[l1]>a[l2])
        return l2;
    else return l1;
}

int NextRightMin(int* a,int* st,int i,int n)
{
    int p=0;int s=0;int e=n-1;int j=n;
    while(p<n-1)
    {
        int m=(s+e)/2;
        if(i<=m)
        {
            if(a[st[2*p+2]]<a[i])
            {
                j=2*p+2;
            }
            p=2*p+1;
            e=m;
        }
        else
        {
            p=2*p+2;
            s=m+1;
        }
    }
    while(j<n-1)
    {
        if(a[st[2*j+1]]<a[i])
        {
            j=2*j+1;
        }
        else
        {
            j=2*j+2;
        }
    }
    return (j-1)/2;
}
int LastMin(int* a,int* st,int n,int i)
{
    int p=0;
    while(p<n-1)
    {
        if(a[st[2*p+2]]<=a[i])
        {
            p=2*p+2;
        }
        else p=2*p+1;
    }
    return p;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    int st[2*n-1];
    a[n]=100000;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(a,st,n);
    //printf("%d",RMQ(st,a,1,6,0,n-1,n,0));
    //printf("%d",NextRightMin(a,st,4,n));
    
}
