#include<stdio.h>
#include<stdlib.h>
void merge(int* arr,int i,int k,int j);
void msort(int* arr,int i, int j);
int main()
{
    FILE* ptr=fopen("test.txt",r);
    int n=fread(ptr,sizeof(int),0,ptr);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=fread(ptr,sizeof(int),0,ptr);
    }
    /*int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    msort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;*/
    
}
void msort(int* arr,int i, int j)
{
    int k=(i+j)/2;
    if(i<j)
    {
        msort(arr,i,k);
        msort(arr,k+1,j);
        merge(arr,i,k,j);
    }
}
void merge(int* arr,int i,int k,int j)
{
    int temp[j-i+1];int r=k+1; int l=i;int p=0;
    while((l<=k)&&(r<=j))
    {
        if(arr[l]<arr[r])
        {
            temp[p]=arr[l];
            p++;l++;
        }
        else
        {
            temp[p]=arr[r];
            p++;r++;
        }
    }
    while(l<=k)
    {
        temp[p]=arr[l];
        p++;l++;
    }
    while(r<=j)
    {
        temp[p]=arr[r];
        p++;r++;
    }
    p=0;
    for(int x=i;x<=j;x++)
    {
        arr[x]=temp[p];
        p++;
    }
}

/*int main()
{
    FILE* fptr=fopen("test.txt",w);
    int n=rand();
    fwrite(n,0,sizeof(int),fptr);
    int a[n];
    int count=0;
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
        fwrite(a[i],0,sizeof(int),fptr);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>2*a[j])
            {
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE* fptr=fopen("test.txt",w);
    int n=rand();
    fwrite(n,0,sizeof(int),fptr);
    int a[n];
    int count=0;
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
        fwrite(a[i],0,sizeof(int),fptr);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>2*a[j])
            {
                count++;
            }
        }
    }
    
    printf("%d",count);
    return 0;
}

