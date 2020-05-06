#include<stdio.h>
#include<stdlib.h>
int partition(int* a,int i, int j, int pivot);
void rqs(int* a,int i,int j)
{
	if(i<j)
	{
        int p=(rand()%(j-i+1))+i;
        int temp=a[i];
        a[i]=a[p];
        a[p]=temp;
		int k=partition(a,i+1,j,a[i]);
		rqs(a,i,k-1);
		rqs(a,k+1,j);
	}
}
int partition(int* a,int i, int j, int pivot)
{
	int l=i;
	int r=j;
	while(l<=r)
	{
		while((l<=r)&&(a[l]<=pivot))
		{
			l++;
		}
		while((l<=r)&&(a[r]>pivot))
		{
			r--;
		}
		if(l<=r)
		{
			int temp=a[l];
			a[l]=a[r];
			a[r]=temp;
            l++;r--;
		}
		
	}
	a[i-1]=a[l-1];
	a[l-1]=pivot;
	return l-1;
}
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	rqs(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
