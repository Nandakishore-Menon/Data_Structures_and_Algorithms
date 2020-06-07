#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+1];int dum[n+1];
    for(int i=0;i<=n;i++)
    {
        a[i]=0;dum[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int choice;
        scanf("%d",&choice);
        int x,y,sumy,sumx;
        switch (choice) {
            case 1:
                //int x;
                scanf("%d",&x);
                dum[x]++;
                while(n>=x)
                {
                    a[x]++;
                    x+= x & -x;
                }
                break;
            case 2:
                //int x;
                scanf("%d",&x);
                
                if(dum[x]<=0)
                {
                    break;
                }
                dum[x]--;
                while(n>=x)
                {
                    a[x]--;
                    x+= x & -x;
                }
                break;
            case 3:
                scanf("%d%d",&x,&y);
                x--;sumy=0;sumx=0;
                while(y>0)//prefix sum of y
                {
                    sumy+=a[y];
                    y-= y & -y;
                }
                while(x>0)//prefix sum of x
                {
                    sumx+=a[x];
                    x-= x & -x;
                }
                printf("%d\n",(sumy-sumx));
                break;
            default:
                break;
        }
    }
}
