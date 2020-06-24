/*https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-watching-fight/
*/
#include<stdio.h>

struct node
{
	int key;
	int height;
	struct node* left;
	struct node* right;
};

struct node* newnode(int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key=val;
	temp->height=1;
	temp->left=temp->right=NULL;
	return temp;
}

struct node* insert(struct node* node,int key)
{
	if(node==NULL)
	{
		return newnode(key);
	}
	if(key<=node->key)
	{
		node->left=insert(node->left, key);
	}
	else if(key>node->key)
	{
		node->right=insert(node->right, key);
	}
	node->height=0;
	if(node->left)
	{
		node->height=node->left->height;
	}
	if(node->right && node->right->height>node->height)
	{
		node->height=node->right->height;
	}
	node->height+=1;
	return node;
}

int main()
{
	int n;
	struct node* root=NULL;
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		root=insert(root,a[i]);
	}
	printf("%d",root->height);
}
