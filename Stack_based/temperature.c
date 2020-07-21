/*
 Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 
 The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 
 */
#include<stdio.h>
void greater_right(int n, int* arr, int* B)
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
			while((top>=0)&&(arr[i]>arr[S[top]]))
			{
				B[S[top]]=i-S[top];
				top--;
			}
			top++;
			S[top]=i;
		}
	}
	while(top>=0)
	{
		B[S[top]]=0;
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
    for(int i =0;i<n;i++)
    {
        printf("%d ", B[i]);
    }
}
