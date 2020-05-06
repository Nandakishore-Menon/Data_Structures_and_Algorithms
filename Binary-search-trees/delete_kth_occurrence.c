/*
You are given a sting of length n containg charater A, B, C, D.
You have m queries, each query is of the type k X, for each query delete the kth occurrence of character X. If the number of X left in the string is less than k, do nothing.
Output: Print the string after m queries. Example: ABCDBCAAB and querries are 2A
1C
1D
3B
2A Output:ABBC
given a
sequence
of n
distinct
intergers
a0, a1, . . . an−1. In
*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct BST
{

    char key;
    int count[4][1];
    struct BST *left, *right,*parent;

};
void update(struct BST* node)
{
    if(node)
    {
        update(node->left);
        update(node->right);
        for(int i=0;i<4;i++)
        {
            node->count[i][0]=0;
            if(node->left)
            {
                node->count[i][0]+=node->left->count[i][0];
            }
            if(node->right)
            {
                node->count[i][0]+=node->right->count[i][0];
            }
        }
        node->count[node->key-'A'][0]+=1;
    }
}

struct BST *
CreateBBST (char A[],int l,int r)
{
  struct BST *node = NULL;
  if (l <= r)
    {

      int m = (l + r) / 2;
      node = (struct BST *) malloc (sizeof (struct BST));
      node->key = A[m];

      node->left = CreateBBST (A, l, m - 1);

      node->right = CreateBBST (A, m + 1, r);
      if (node->right)
    node->right->parent = node;
      if (node->left)
    node->left->parent = node;
    }

  return node;
}
void
deletenode (struct BST **root, struct BST *node)
{
  if (node->left && node->right)
    {
        struct BST *temp = node->left;struct BST* dum=node->left;
        while (temp->right)
            temp = temp->right;
        if(dum->right==NULL)
            dum->count[temp->key-'A'][0]--;
        while (dum->right)
        {
            dum->count[temp->key-'A'][0]--;
            dum = dum->right;
        }
      node->key = temp->key;
        for(int i=0;i<4;i++)
        {
            node->count[i][0]=0;
            node->count[i][0]+=node->left->count[i][0]+node->right->count[i][0];
        }
        node->count[node->key-'A'][0]++;
      node = temp;
    }

  struct BST *child, *p = node->parent;
  if (node->left)
    child = node->left;
  else
    child = node->right;
  if (*root == node)
    *root = child;
  if (child)
    child->parent = p;
  if (p)
  {if (p->left == node)
      p->left = child;
    else
      p->right = child;
  }
  //free (node);

}

void
Delete (struct BST **root,char x,int k)
{
    struct BST *node = *root;
    while(node)
    {
        if(node->left)
        {
            if(node->left->count[x-'A'][0]<k)
            {
                k-=node->left->count[x-'A'][0];
                if(k==1)
                {
                    if(node->key==x)
                    {
                        deletenode(root,node);
                        break;
                    }
                }
                if(node->key==x)
                {
                    k--;
                }
                if(node->right)
                {
                    node->count[x-'A'][0]--;
                    node=node->right;
                }
            }
            else
            {
                node->count[x-'A'][0]--;
                node=node->left;
            }
        }
        else
        {
            if(k==1)
            {
               if(node->key==x)
                {
                    deletenode(root,node);
                    break;
                }
            }
            if(node->right)
            {
                node->count[x-'A'][0]--;
                node=node->right;
            }
            
        }
    }
  
}




void
Inorder (struct BST *node)
{
  if (node)
    {
      Inorder (node->left);
      printf ("%c ", node->key);
        /*for(int i=0;i<4;i++)
        {
            printf("%c: %d ",'A'+i,node->count[i][0]);
        }*/
        
      Inorder (node->right);
    }
}

int main()
{
    int n;    scanf("%d",&n);char a[n];

    int m;
    scanf("%d",&m);
    scanf("%s",a);
    struct BST* root=CreateBBST(a,0,n-1);
    //Inorder(root);
    update(root);
    for(int i=0;i<m;i++)
    {
        printf("Enter x k:");
        int k;char x[1];
        scanf("%s",x);
        scanf("%d",&k);
        if(root->count[x[0]-'A'][0]>=k)
        {
            Delete(&root,x[0],k);
        }
        printf("Resultant string: ");
        Inorder(root);
        printf("\n");
    }
    /*Inorder(root);
    Delete(&root,'D',1);
    Inorder(root);
    //update(root);
    Delete(&root,'B',2);
    //update(root);
    Inorder(root);
    Delete(&root,'A',2);
    Inorder(root);*/
}
