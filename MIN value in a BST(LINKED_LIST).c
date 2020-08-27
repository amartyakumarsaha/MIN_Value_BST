#include<stdio.h>
#include<stdlib.h>
struct node *insert();
struct node *getNewNode();
int minNode();
void inorder();
struct node{
	int key;
	struct node *left;
	struct node *right;
};
int main()
{
	struct node *root=NULL;
	root=insert(root,100);
	root=insert(root,50);
	root=insert(root,200);
	root=insert(root,150);
	root=insert(root,300);
	
	inorder(root);
	printf("\n min value is :-%d",minNode(root));
	return 0;
}
struct node *insert(struct node *root,int val)
{
	if(root==NULL)
		return getNewNode(val);
	if(root->key<val)
		root->right=insert(root->right,val);
	else if(root->key>val)
		root->left=insert(root->left,val);
	
	return root;
}
struct node *getNewNode(struct node *root,int val)
{
	root=(struct node*)malloc(sizeof(struct node));
	root->key=val;
	root->left=NULL;
	root->right=NULL;
	
	return root;
}
void inorder(struct node *root)
{
	if(root==NULL)
	  return ;
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
}
int minNode(struct node *root)
{
	struct node *current=root;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	return current->key;
}
