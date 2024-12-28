#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
}*root=NULL;
int getHeight(struct node *n)
{
	if(n==NULL)
		return 0;
	return n->height;
}
struct node *createNode(int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->height=1;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}
int getBalanceFactor(struct node *n)
{
	if(n==NULL)
		return 0;
	return getHeight(n->left)-getHeight(n->right);
}
struct node *leftRotate(struct node *n)
{
	struct node *y=n->right;
	struct node*t2=y->left;
	y->left=n;
	n->right=t2;
	n->height=max(getHeight(n->right),getHeight(n->left))+1;
	y->height=max(getHeight(y->right),getHeight(y->left))+1;
	return y;
}
struct node *rightRotate(struct node *n)
{
	struct node *x=n->left;
	struct node *t2=x->right;
	x->right=n;
	n->left=t2;
	x->height=max(getHeight(x->right),getHeight(x->left))+1;
	n->height=max(getHeight(n->right),getHeight(n->left))+1;
	return x;
}
struct node *insert(struct node *node,int data)
{
	if(node==NULL)
		return createNode(data);
	if(data<node->data)
		node->left=insert(node->left,data);
	else if(data>node->data)
		node->right=insert(node->right,data);
	else 
		return node;
	node->height=1+max(getHeight(node->left),getHeight(node->right));
	int bf=getBalanceFactor(node);
	if(bf>1&&data<node->left->data)
		return rightRotate(node);
	if(bf<-1&&data>node->right->data)
		return leftRotate(node);
	if(bf>1&&data>node->left->data)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(bf<-1&&data<node->right->data)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
void preOrder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main()
{
	int option,val;
	printf("***AVL Tree***\n");
	while(1)
	{
		printf("1.Insert\n2.Display\n3.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&val);
				root=insert(root,val);
				break;
			case 2:
				preOrder(root);
				printf("\n");
				break;
			case 3:
				exit(0);	
		}
	}
	return 0;
}
