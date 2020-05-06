#include<stdio.h>
void greater_right(int n, int* arr, int* B)//computes the first element greater than a given element to the right
{
	int S[n];
	int top=-1;
	for(int i=0; i<n; i++)
	{
		if(top<0)
		{
			top++;
			S[top]=i;
		}
		else
		{
			while((top>=0)&&(arr[i]>=arr[S[top]]))
			{
				B[S[top]]=i;
				top--;
			}
			top++;
			S[top]=i;
		}
	}
	while(top>=0)
	{
		B[S[top]]=-1;
		top--;
	}
}

void greater_left(int n, int* arr, int* B)//computes the first element greater than a given element to the left
{
	int S[n];
	int top=-1;
	for(int i=n-1; i>=0; i--)
	{
		if(top<0)
		{
			top++;
			S[top]=i;
		}
		else
		{
			while((top>=0)&&(arr[i]>=arr[S[top]]))
			{
				B[S[top]]=i;
				top--;
			}
			top++;
			S[top]=i;
		}
	}
	while(top>=0)
	{
		B[S[top]]=-1;
		top--;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int B[n];
	greater_right(n, arr, B);
	for(int j=0; j<n; j++)
		printf("%d ", B[j]);
	printf("\n");
	greater_left(n, arr, B);
	for(int j=0; j<n; j++)
		printf("%d ", B[j]);
}
