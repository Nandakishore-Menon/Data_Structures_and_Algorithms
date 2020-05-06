#include<stdio.h>
void insertion(int* a,int n)
{
    for(int i=1;i<=n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while((j>=0)&&(a[j]>temp))
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int arr[]={1,3,2,5,4,8,6,9,0,7};
    insertion(arr,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
}


