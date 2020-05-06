#include<stdio.h>
#include<stdlib.h>
int size(int n)
{
    int p=1;
    while(p<=n)
    {
        p*=2;
    }
    return p;
}
void build(int* st,int s)
{
    int n=size(s);
    
    for(int i=0;i<s;i++)
    {
        st[n+i-1]=1;
    }
    for(int i=n+s-1;i<2*n-1;i++)
    {
        st[i]=0;
    }
    for(int i=n-2;i>=0;i--)
    {
        st[i]=st[2*i+1]+st[2*i+2];
    }
}
void update(int* st,int i,int n)
{
    if(st[n-1+i]!=0)
    {
    st[n-1+i]=0;
    i=(n-1+i-1)/2;
    while(i>0)
    {
        
        st[i]--;
        i=(i-1)/2;
    }
    st[0]--;
    }
}
int kone(int* st,int n,int k)
{
    if(st[0]<k)
    {
        return -1;
    }
    int p=0;
    while(p<n-1)
    {
        if(k<=st[2*p+1])
        {
            p=2*p+1;
        }
        else
        {
            k-=st[2*p+1];
            p=2*p+2;
            
        }
    }return p-n+1;
    
}
int main()
{
    int nn;
    scanf("%d",&nn);
    int n=size(nn);
    int* st=calloc((2*n-1),sizeof(int));
    build(st,nn);
    int a;
    scanf("%d",&a);
    int c[a];int k[a];
    for(int i=0;i<a;i++)
    {
        scanf("%d",&c[i]);
        scanf("%d",&k[i]);
    }
    for(int i=0;i<a;i++)
    {
        if(c[i]==0)
        {
            update(st,k[i]-1,n);
        }
        else
        {
            int y=kone(st,n,k[i]);
            if(y!=-1)
                y++;
            printf("%d\n",y);
        }
    }
    /*for(int i=0;i<2*n-1;i++)
    {
        printf("%d ",st[i]);
    }*/
    // printf("kone complete\n");
}


