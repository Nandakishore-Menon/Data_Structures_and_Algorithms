#include<stdio.h>
#include<stdlib.h>

void increase(int** bit,int n,int ch,int i,int x)
{
    while(i<=n)
    {
        bit[ch][i]+=x;
        int y=(i&(-i));
        i+=y;
    }
}

int ps(int** bit,int ch,int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=bit[ch][i];
        i-=(i&(-i));
    }
    return sum;
}
int main()
{
    int n,q;scanf("%d",&n);scanf("%d",&q);
    int* bit[26];
    for(int i=0;i<26;i++)
    {
        bit[i]=(int*)malloc((n+1)*sizeof(int));
    }
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<n;j++)
        {
            bit[i][j]=0;
        }
    }
    char str[n];
    scanf("%s",str);
    for(int i=1;i<=n;i++)
    {
        increase(bit,n,str[i-1]-'a',i,1);
    }
    for(int i=0;i<q;i++)
    {
        int choice;
        scanf("%d",&choice);
        if(choice==0)
        {
            int index; char ch[5];
            scanf("%d",&index);
            scanf("%s",ch);
            //printf("%c",str[index-1]);
            //printf("%d",index);
            //getchar();
            increase(bit,n,str[index-1]-'a',index,-1);
            str[index-1]=ch[0];
            increase(bit,n,str[index-1]-'a',index,1);
            //printf("%s",str);
        }
        else
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            if((r>=l)&&(r-l+1>=k))
            {
                int i;
                int count=0;
                for(i=0;i<26;i++)
                {
                    count+=ps(bit,i,r)-ps(bit,i,l-1);
                    if(count>=k)
                        break;
                }
                printf("%c\n",i+'a');
            }
            else
                printf("Out of range\n");
        }
    }
}
