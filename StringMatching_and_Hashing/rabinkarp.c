/*
 single pattern rabin-karp algorithm(rolling hash without hash table)
 */
#include<stdio.h>
#include<string.h>
#include<math.h>


void rabin(char* pat, char* text)
{
    int plen=strlen(pat);
    long long int pval=0;
    long long int val=0;
    int k=0;
    int index[strlen(text)/plen];
    for(int i=0;i<plen;i++)
    {
        pval=pval*10+(pat[i]-'a');
        val=val*10+(text[i]-'a');
        //printf("%lld %lld\n",pval,val);
    }
    for(int i=0;i<=strlen(text)-plen;i++)
    {
        //printf("%lld\n",val);
        if(pval==val)
        {
            for(int j=0;j<plen;j++)
            {
                if(text[i+j]!=pat[j])
                {
                    break;
                }
                if(j==plen-1)
                {
                    index[k]=i;
                    k++;
                }
            }
        }
        val= val-((text[i]-'a')*(pow(10,plen-1)));
        //printf("%lld\n",val);
        if(i+plen-1<=strlen(text))
        {
            val= val*10+(text[i+plen]-'a');
        }
    }
    printf("Patten found at the following indices:\n");
    for(int i=0;i<k;i++)
    {
        printf("%d\n",index[i]);
    }
}
int main()
{
    char text[]="madadisacooldadbrosdsvvffdad";
    char pat[]="dad";
    rabin(pat,text);
    return 0;
}
