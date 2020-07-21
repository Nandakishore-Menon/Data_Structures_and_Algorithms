/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:

11110

11010

11000

00000

Output: 1

 

Example 2:

Input:

11000

11000

00100

00011

 

Output: 3

*/


#include<stdio.h>
#include<stdlib.h>


int dfs(int i,int j,int m,int n,int map[][n])
{
    if(i<0||i>=m)
        return 0;
    
    else if(j<0||j>=n)
        return 0;

    else if(map[i][j]==0)
        return 0;
    else
        map[i][j]=0;

    dfs(i+1,j,m,n,map);
    dfs(i-1,j,m,n,map);
    dfs(i,j+1,m,n,map);
    dfs(i,j-1,m,n,map);
    return 0;
}



int main()
{
    int m,n;
    scanf("%d%d",&m,&n);//row,column
    if (m==0 || n==0)
        return 0;
    int map[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    //getchar();
    int isl=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            //getchar();
            if(map[i][j]==1)
            {
                dfs(i,j,m,n,map);
                //getchar();
                isl++;
            }
        }
    }
    
    printf("%d",isl);
    return 0;
}
