#include<stdio.h>
void smaller_right(int n, int* arr, int* B);//computes the first element smaller than a given element to the right
void smaller_left(int n, int* arr, int* B);//computes the first element smaller than a given element to the left
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
	smaller_right(n, arr, B);
	for(int j=0; j<n; j++)
		printf("%d ", B[j]);
	printf("\n");
	smaller_left(n, arr, B);
	for(int j=0; j<n; j++)
		printf("%d ", B[j]);
}

void smaller_right(int n, int* arr, int* B)
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
			while((top>=0)&&(arr[i]<=arr[S[top]]))
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

void smaller_left(int n, int* arr, int* B)
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
			while((top>=0)&&(arr[i]<=arr[S[top]]))
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
