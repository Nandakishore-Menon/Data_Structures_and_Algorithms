/*
Implementation of an Interval tree that allows same left end point of the intervals.
*/
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>

struct bst
{
    int key,max,high;
    struct bst* left,*right;
    int height;
    struct high* hightree;
};
struct high
{
    int key;
    struct high *left,*right;
    //int height;
};

int
Max (int x, int y)
{
  if (x < y)
    return y;
  else
    return x;
}

int
Min (int x, int y)
{
  if (x < y)
    return x;
  else
    return y;
}

int Height (struct bst *node)
{
  if (node)
    {
      if (node->left && node->right)
    return 1 + Max (node->left->height, node->right->height);

      else if (node->left)
    return 1 + node->left->height;
      else if (node->right)
    return 1 + node->right->height;
      else
    return 0;

    }

  else
    return -1;
}

void
Updatemax (struct bst *node)
{
  if (node)
    {
      node->max = node->high;
      if (node->left && node->left->max > node->high)
          node->max = node->left->max;
      if (node->right && node->right->max > node->max)
          node->max = node->right->max;
      //return node->max;
    }
}

struct bst* Search (struct bst *node,int X)
{

  while (node)
    {
      if (X == node->key)
    return node;
      else if (X < node->key)
    node = node->left;
      else
    node = node->right;
    }
  return NULL;
}

bool AVL (struct bst *node)
{
  if (abs (Height (node->left) - Height (node->right)) < 2)
    return true;
  else
    return false;
}

struct bst* newNode(int l,int r)
{
    
  struct bst *temp = (struct bst *) malloc (sizeof (struct bst));
  temp->key = l;
  temp->max = r;
  temp->high=r;
  temp->hightree=(struct high *) malloc (sizeof (struct high));
  temp->hightree->key=r;
  temp->left = temp->right = NULL;
  temp->height = 0;
  return temp;
}
struct bst *Rotate (struct bst *Z)
{
  struct bst *X, *Y, *T1, *T2, *T3, *T4;
  int c = 0;
  if (Height (Z->left) + 1 == Z->height)
    Y = Z->left;
  else
    {
      Y = Z->right;
      c++;
    }
  c = c * 2;
  if (Height (Y->left) + 1 == Y->height)
    X = Y->left;
  else
    {
      X = Y->right;
      c++;
    }

  if (c == 0)
    {
      T3 = Y->right;
      Y->right = Z;
      Z->left = T3;
      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Updatemax (Z);
      Updatemax (X);
      Updatemax (Y);
      return Y;

    }
  else if (c == 3)
    {

      T2 = Y->left;
      Y->left = Z;
      Z->right = T2;

      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Updatemax (Z);
      Updatemax (X);
      Updatemax (Y);
      return Y;
    }
  else if (c == 1)
    {

      T2 = X->left;
      T3 = X->right;
      Y->right = T2;
      Z->left = T3;
      X->left = Y;
      X->right = Z;

      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Updatemax (Z);
      Updatemax (Y);
      Updatemax (X);
      return X;

    }
  else
    {
      T2 = X->left;
      T3 = X->right;
      Y->left = T3;
      Z->right = T2;
      X->left = Z;
      X->right = Y;

      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Updatemax (Z);
      Updatemax (Y);
      Updatemax (X);
      return X;
    }


}

struct bst* Insert (struct bst *node,int key,int r)
{
  if (!node)
    return newNode (key, r);
  if (key < node->key)
    node->left = Insert (node->left, key, r);
  else if (key > node->key)
    node->right = Insert (node->right, key, r);
  node->height = Height (node);
  Updatemax (node);
  if (!AVL (node))
    {
      node = Rotate (node);
    }
  return node;
}
struct high *newhigh (int key)
{
  struct high *temp = (struct high *) malloc (sizeof (struct high));
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}
struct high *inserthigh (struct high *node,int key)
{
  
  if (!node)
    return newhigh(key);

  // Otherwise, insert in left subtree or right subtree
  if (key < node->key)
    node->left = inserthigh(node->left, key);
  else if (key > node->key)
    node->right =inserthigh(node->right, key);
  return node;
}

struct bst *
Overlap (struct bst *node,int l,int r)
{

  while (node)
    {
      if (l <= node->high && node->key <= r)
    return node;
      if (node->left && node->left->max >= l)
    node = node->left;
      else
    node = node->right;
    }
  return NULL;
}

struct bst*
Delete (struct bst *node, int X)
{
  if (!node)
    return node;

  // Recursive calls for ancestors of
  // node to be deleted
  if (node->key > X)
    {
      node->left = Delete (node->left, X);
      node->height = Height (node);
      Updatemax (node);
      if (!AVL (node))
    node = Rotate (node);

      return node;
    }
  else if (node->key < X)
    {
      node->right = Delete (node->right, X);
      node->height = Height (node);
      Updatemax (node);
      if (!AVL (node))
    node = Rotate (node);
      return node;
    }


  if (node->left && node->right)
    {
      struct bst *temp = node->left;
      while (temp->right)
    temp = temp->right;
      node->key = temp->key;
      node->high = temp->high;
      node->left = Delete (node->left, temp->key);
      Updatemax (node);
    }
  else
    {
      struct bst *child;
      if (node->left)

    child = node->left;
      else
    child = node->right;
      free (node);
      return child;
    }
}
struct high *searchhigh (struct high *node,int X)
{

  while (node)
    {
      if (X == node->key)
    return node;
      else if (X < node->key)
    node = node->left;
      else
    node = node->right;
    }
  return NULL;
}
struct high *
deletehigh (struct high *node,int X)
{
  if (!node)
    return node;

  // Recursive calls for ancestors of
  // node to be deleted
  if (node->key > X)
    {
      node->left = deletehigh (node->left, X);
      return node;
    }
  else if (node->key < X)
    {
      node->right = deletehigh (node->right, X);
      return node;
    }
  if (node->left && node->right)
    {
      struct high *temp = node->left;
      while (temp->right)
          temp = temp->right;
      node->key = temp->key;
      node->left = deletehigh (node->left, temp->key);
    }
  else
    {
      struct high *child;
      if (node->left)
    child = node->left;
      else
    child = node->right;
      free (node);
      return child;
    }

}
void update(struct bst* node,int x)
{
    if (node)
    {
        if(node->key>x)
        {
            update(node->left,x);
        }
        else if(node->key<x)
        {
            update(node->right,x);
        }
        
        Updatemax(node);
    }

}

void deletenode(struct bst** node,int key,int high)
{
    struct bst* temp=Search(*node,key);
    if((temp->hightree->left==NULL)&&(temp->hightree->right==NULL))
        *node=Delete(*node,key);
    else
    {
        temp->hightree=deletehigh(temp->hightree,high);
        struct high* dum=temp->hightree;
        while(dum->right)
        {
            dum=dum->right;
        }
        temp->high=dum->key;
        update(*node,key);
    }
}
void
Inorder (struct bst *node)
{
  if (node)
    {
      Inorder (node->left);
      printf ("%d: high: %d   max:%d \n", node->key, node->high, node->max);
      Inorder (node->right);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int s[n];int e[n];struct bst* root=NULL;
    printf("Input intervals in the format: start<space>end\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        scanf("%d",&e[i]);
        struct bst* temp=Search(root,s[i]);
        if(temp==NULL)
            root=Insert (root,s[i],e[i]);
        else
        {
            if(temp->high<e[i])
                temp->high=e[i];
            if(temp->max<e[i])
                temp->max=e[i];
            struct high* node=temp->hightree;
            node=inserthigh(node,e[i]);
        }
            
    }
    while(root)
    {
        printf("%d\n",root->key);
        root=root->right;
    }
   /* int l,r;
    printf("\nEnter interval to delete:\n");
    scanf("%d",&l);scanf("%d",&r);
    deletenode(&root,l,r);*/
    //Inorder(root);
    /*printf("\nEnter interval to check overlap:\n");
    scanf("%d",&l);scanf("%d",&r);
    struct bst* temp=Overlap(root,l,r);
    if(temp==NULL)
    {
        printf("\nNo overlap\n");
    }
    else
    {
        printf("\nOverlaps with the interval [%d,%d]\n",temp->key,temp->high);
    }*/
}

