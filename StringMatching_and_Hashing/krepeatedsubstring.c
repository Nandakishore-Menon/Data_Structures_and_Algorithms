#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
    int data;
    struct node* next;
    int count;
};

long long int hash(char* text,int* x,int plen)
{
    long long int val=text[0]-'a';
    for(int i=1;i<plen;i++)
    {
        *x=10*(*x)%101;
        val= (val*10+(text[i]-'a'))%101;
    }
    //val%=101;
    return val;
}
int scomp(char* s,int i,int j,int l)
{
    //printf("in");
    for(int x=0;x<l;x++)
    {
        if(s[i+x]!=s[j+x])
        {
           // printf("\nnot equal\n");
            return 0;
        }
    }
    //printf("\nequal\n");
    return 1;
}

int check(char* s,int l,int k,int n)
{
    //printf("%d\n\n\n",l);
    struct node* table[101];int x=10;
    for(int i=0;i<101;i++)
    {
        //table[i]=(struct node*)malloc(sizeof(struct node));
        table[i]=NULL;
        //table[i]->count=1;
    }
    //printf("done\n");
    long long int val = hash(s,&x,l);
    //printf("%d\n",l);
    //getchar();
    for(int i=0;i<=n-l;i++)
    {
        
        if(table[val%101]==NULL)
        {
            //printf("case 1\n");
            struct node* temp=malloc(sizeof(struct node));
            temp->data=i;
            temp->count=1;
            table[val%101]=temp;
            temp->next=NULL;
            //printf("%c added at %d\n",s[temp->data],temp->data);
        }
        else
        {
            //printf("case2\n");
            struct node* dum= table[val%101];
            int flag=0;
            while(dum!=NULL)
            {
                
                if(scomp(s,i,dum->data,l)==1)
                {
                   // printf("%c at %d matched with one at %d\n",s[i],i,dum->data);
                    dum->count+=1;
                    flag=1;
                    if(dum->count==k)
                    {
                        /*for(int j=0;j<l;j++)
                        {
                            printf("%c",s[dum->data+j]);
                        }
                        printf("\n");
                        printf("%d\n\n\n",l);*/
                        for(int j=0;j<101;j++)
                        {
                            free(table[j]);
                        }
                        return 1;
                    }
                    break;
                }
                if(dum->next!=NULL)
                    dum=dum->next;
                else
                    break;
                    
            }
            if (flag==0)
            {
                struct node* dummy= malloc(sizeof(struct node));
                dummy->data=i;
                dummy->count=1;
                dummy->next=NULL;
                dum->next=dummy;
               // printf("%c added at %d\n",s[dummy->data],dummy->data);
            }
            
        }
        val=(10*val+(s[i+l]-'a')-x*(s[i]-'a'))%101;
        if(val<0)
        {
            val+=101;
        }
       // printf("%lld\n",val);
    }
        
    for(int i=0;i<101;i++)
    {
        free(table[i]);
    }
    return 0;
}
int store=0;
int binarysearch(int i,int j,char* s,int k,int n)
{
    //printf("%d %d\n",i,j);
    if(i<=j)
    {
        /*if(j=i+1)
        {
            if(check(s,j,k,n)==1)
            {
                //printf("%d",j);
                return j;
            }
            if(check(s,j,k,n)==1){
                //printf("%d",i);
                return i;
            }
        }*/
        int l=(i+j)/2;
        //printf("%d %d %d\n",i,j,l);
        if (check(s,l,k,n)==1)
        {   //printf("Case1\n");
            if(l>store)
                store=l;
            binarysearch(l+1,j,s,k,n);}
        else
        {
            binarysearch(i,l-1,s,k,n);}
    }
    /*if(i==j)
    {   //printf("%d",i);
        return i;}*/
}
int main()
{
    int n,k;
    scanf("%d",&k);
    scanf("%d",&n);
    char text[n];
    scanf("%s",text);
    //char text[]="100100100100100";
    if(k==1)
    {printf("%d",n);
        return 0;
    }
    long long int result=binarysearch(1,n-k+1,text,k,n);
    printf("%d",store);
    return 0;
}


