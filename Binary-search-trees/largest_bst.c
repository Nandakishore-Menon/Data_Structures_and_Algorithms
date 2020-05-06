/*
Given a binary tree with some keys at each node, implement an efficient algorithm to compute the largest subtree that is BST.
Return the root of the largest subtree that is BST.
*/
#include<stdio.h>
#include<stdlib.h>
struct bt
{
    int data;
    struct bt* left;
    struct bt* right;
};
struct val
{
    int torf;
    int size,min,max;
};
int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
struct val* postorder(struct bt* node,int* size,struct bt** root)
{
    if(node)
    {
        
        struct val* a;
        struct val* b;
        if(node->left==NULL)
            a=NULL;
        else
            a=postorder(node->left,size,root);
        if(node->right==NULL)
            b=NULL;
        else
            b=postorder(node->right,size,root);
        struct val* temp=malloc(sizeof(struct val));
        if((a==NULL)&&(b==NULL))
        {
            temp->size=1;
            temp->min=temp->max=node->data;
            temp->torf=1;
            //printf("\nnode:%d torf:%d size:%d min:%d  max : %d\n",node->data,temp->torf,temp->size,temp->min,temp->max);
            //return temp;
        }
        else
        {
            if((a!=NULL)&&(b!=NULL))
            {
                if((a->torf)&&(b->torf))
                {
                    if((a->max<node->data)&&(b->min>node->data))
                    {
                        temp->torf=1;
                        temp->size=a->size+b->size+1;
                        temp->min=a->min;
                        temp->max=b->max;
                    }
                    else
                    {
                        temp->torf=0;
                        temp->size=max(a->size,b->size);
                    }
                }
                else
                {
                    temp->torf=0;
                    temp->size=max(a->size,b->size);
                }
                //printf("\nnode:%d torf:%d size:%d min:%d  max : %d\n",node->data,temp->torf,temp->size,temp->min,temp->max);
            }
            else if(b!=NULL)
            {
                if((b->torf)&&(node->data<b->min))
                {
                    
                    temp->torf=1;
                    temp->size=1+b->size;
                    temp->min=node->data;
                    temp->max=b->max;
                }
                else
                {
                    temp->torf=0;
                    temp->size=b->size;
                }
            }
            else if (a!=NULL)
            {
                if((a->torf)&&(node->data>a->max))
                {
                    
                    temp->torf=1;
                    temp->size=1+a->size;
                    temp->max=node->data;
                    temp->min=a->min;
                }
                else
                {
                    temp->torf=0;
                    temp->size=a->size;
                }
                //printf("\nnode:%d torf:%d size:%d min:%d  max : %d\n",node->data,temp->torf,temp->size,temp->min,temp->max);

            }
            
        }
        if(temp->size>*size)
        {
            *size=temp->size;
            *root=node;
            //printf("\nReturn node variable value: %d   size:%d\n",(*root)->data,*size);
        }
        return temp;
    }

}

struct bt* newNode(int data)
{
    struct bt* new = malloc(sizeof(struct bt));
    new->data = data;
    new->left = new->right = NULL;
  
    return(new);
}
int main()
{
    struct bt *root= newNode(60);
    struct bt* ans;int size=0;
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    postorder(root,&size,&ans);
    printf(" value of root of the largest BST is %d and its size is %d\n",ans->data,size);
    return 0;
}
