/*
An array of size n and m queries/operations.
Each operation has one of the following two types:

U X Y : Update the value at the Xth index of the array with Y.

Q X C : Calculate the length of the longest subarray that starts at Xth index and satisfy following inequality

A[X]-C ≤ V ≤ A[X] + C

Where V is any value from the chosen subarray.

*/
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
void build(int* A,int* minst,int* maxst,int n)
{
    int s=size(n);
    for(int i=0;i<n;i++)
    {
        minst[s+i-1]=i;
        maxst[s+i-1]=i;
    }
    for(int i=n;i<s;i++)
    {
        minst[s+i-1]=n+1;
        maxst[s+i-1]=n;
    }
    for(int i=s-2;i>=0;i--)
    {
        if(A[minst[2*i+1]]>A[minst[2*i+2]])
        {
            minst[i]=minst[2*i+2];
        }
        else
        {
            minst[i]=minst[2*i+1];
        }
        if(A[maxst[2*i+1]]<A[maxst[2*i+2]])
        {
            maxst[i]=maxst[2*i+2];
        }
        else
        {
            maxst[i]=maxst[2*i+1];
        }
    }
   // printf("build done\n");
}

int max(int x, int y)
{
    if(x>y)
        return x;
    return y;
}
int min(int x, int y)
{
    if(x>y)
        return y;
    return x;
}

void update(int* A,int* minst,int* maxst,int x,int i,int n)
{
    A[i-1]=x;
    i=(n-1+i-1)/2;
    while(i>0)
    {
        if(A[minst[2*i+1]]>A[minst[2*i+2]])
        {
            minst[i]=minst[2*i+2];
        }
        else
        {
            minst[i]=minst[2*i+1];
        }
        if(A[maxst[2*i+1]]<A[maxst[2*i+2]])
        {
            maxst[i]=maxst[2*i+2];
        }
        else
        {
            maxst[i]=maxst[2*i+1];
        }
        i=(i-1)/2;
    }
    if(A[minst[2*i+1]] > A[minst[2*i+2]])
    {
            minst[i]=minst[2*i+2];
    }
    else
    {
            minst[i]=minst[2*i+1];
    }
    if(A[maxst[2*i+1]] < A[maxst[2*i+2]])
    {
            maxst[i]=maxst[2*i+2];
    }
    else
    {
            maxst[i]=maxst[2*i+1];
    }
   // printf("update done\n");
}

int minquery(int* minst,int* a,int i,int x,int n)
{
    int p=size(n)+i-1;int s=size(n);
    while(p>0)
    {
        int parent=(p-1)/2;
       
        if(p==2*parent+1)
        {
            if((a[i]-x)<=a[minst[2*parent+2]])
            {
                p=parent;continue;
                
            }
            else
            {
                p=2*parent+2;break;
            }
        }
        p=(p-1)/2;
    }
    if(p==0)
    {
        //printf("minquery done\n");
        return n-1;
    }
    while(2*p+2<2*s-1)
    {
        if(a[i]-x>a[minst[2*p+1]])
        {
            p=2*p+1;
        }
        else
        {
            p=2*p+2;
        }
    }
    //printf("minquery done\n");
    return minst[p]-1;
    
}
int maxquery(int* maxst,int* a,int i,int x,int n)
{
    int p=size(n)+i-1;
    while(p>0)
    {
        int parent=(p-1)/2;
        
        if(p==2*parent+1)
        {
            if(a[i]+x>=a[maxst[2*parent+2]])
            {
                p=parent;continue;
                
            }
            else
            {
                p=2*parent+2;break;
            }
            
        }
        p=(p-1)/2;
    }
    if(p==0)
    {
       // printf("maxquery done\n");
        return n-1;
    }
    while(2*p+2<2*(size(n))-1)
    {
        if(a[i]+x<a[maxst[2*p+1]])
        {
            p=2*p+1;
        }
        else
        {
            p=2*p+2;
        }
        
    }
    //printf("Maxquery done\n");
    return maxst[p]-1;
    
}
int mininrange(int* minst,int* a,int i,int j,int s,int e,int n,int p)
{
    if((j<s)||(i>e))
    {
        return n+1;
    }
    if((i<=s) && (e<=j))
    {
        return minst[p];
    }
    int m=(s+e)/2;
    int l1=mininrange(minst,a,i,j,s,m,n,2*p+1);
    int l2=mininrange(minst,a,i,j,m+1,e,n,2*p+2);
    if(a[l1]>a[l2])
        return l2;
    else return l1;
}
int maxinrange(int* maxst,int* a,int i,int j,int s,int e,int n,int p)
{
    if((j<s)||(i>e))
    {
        return n;
    }
    if((i<=s) && (e<=j))
    {
        return maxst[p];
    }
    int m=(s+e)/2;
    int l1=maxinrange(maxst,a,i,j,s,m,n,2*p+1);
    int l2=maxinrange(maxst,a,i,j,m+1,e,n,2*p+2);
    if(a[l1]<a[l2])
        return l2;
    else return l1;
}
int main()
{
    int n,m;
    scanf("%d",&n);scanf("%d",&m);
    int a[n+2];
    a[n]=-1073741823;
    a[n+1]=1073741823;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int s=size(n);
    int minst[2*s-1];
    int maxst[2*s-1];
    int answers[m][2];int j=0;
    build(a,minst,maxst,n);
    /*for(int i=0;i<2*s-1;i++)
    {
        printf("%d %d\n",minst[i],maxst[i]);
    }*/
    for(int i=0;i<m;i++)
    {
        char c[2];
        scanf("%s",c);
        if(c[0]=='U')
        {
            //printf("inside U\n");
            int index,x;
            scanf("%d",&index);
            scanf("%d",&x);
            update(a,minst,maxst,x,index,s);
        }
        else
        {
            //printf("inside Q\n");
            int index,k;
            scanf("%d",&index);
            scanf("%d",&k);
            
            if(k>0)
            {int end1=minquery(minst,a,index-1,k,n);
            int end2=maxquery(maxst,a,index-1,k,n);
            int end=min(end1,end2);
           // printf("%d  %d\n\n\n",end1,end2);
            int z;
            int z1= mininrange(minst,a,index-1,end,0,s-1,n,0);
            int z2= maxinrange(maxst,a,index-1,end,0,s-1,n,0);
            //printf("%d  %d\n\n\n",z1,z2);
            if(a[index-1]-a[z1]>a[z2]-a[index-1])
                z=a[index-1]-a[z1];
            else
                z=a[z2]-a[index-1];
            end=end-index+2;
            answers[j][0]=end;
            answers[j][1]=z;
            j++;
            }   // printf("%d %d\n",end,z);}
            else
            {
                answers[j][0]=-1;
                answers[j][1]=-1;
                j++;
            }
        }
            
    }
        for(int y=0;y<j;y++)
        {
            printf("%d %d\n",answers[y][0],answers[y][1]);
        }
    return 0;
}
