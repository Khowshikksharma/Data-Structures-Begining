#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL;
struct node *insert(struct node *root,int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
		root=newnode;
	if(root->data<val)
		root->right=insert(root->right,val);
	else if(root->data>val)
		root->left=insert(root->left,val);
	return root;
}
void preorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void postorder(struct node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
struct node *search(struct node *root,int data)
{
	if(root==NULL)
		return NULL;
	if(data<root->data)
		return search(root->left,data);
	else if(data>root->data)
		return search(root->right,data);
	else
		return root;
}
struct node *findmin(struct node *root)
{
	if(root==NULL)
		return NULL;
	else if(root->left==NULL)
		return root;
	else
		return findmin(root->left);
}
struct node *del(struct node *root,int data)
{
	if(root==NULL)
		printf("BST is empty\n");
	else if(data<root->data)
		root->left=del(root->left,data);
	else if(data>root->data)
		root->right=del(root->right,data);
	else
	{
		if(root->left==NULL&&root->right==NULL)
			root=NULL;
		else if(root->left==NULL)
			root=root->right;
		else if(root->right==NULL)
			root=root->left;
		else
		{
			struct node *t = findmin(root->right);
			root->data=t->data;
			root->right=del(root->right,t->data);
		}
	}
	return root;
}
main()
{
	int option,val,choise;
	struct node *key;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&val);
				root=insert(root,val);
				break;
			case 2:
				printf("Enter the value to be deleted:");
				scanf("%d",&val);
				root=del(root,val);
				break;
			case 3:
				printf("1.Pre Order\n2.In Order\n3.Post Order\n");
				scanf("%d",&choise);
				switch(choise)
				{
					case 1:
						preorder(root);
						printf("\n");
						break;
					case 2:
						inorder(root);
						printf("\n");
						break;
					case 3:
						postorder(root);
						printf("\n");
						break;
				}
				break;
			case 4:
				printf("Enter the value:");
				scanf("%d",&val);
				key=search(root,val);
				if(key->data==val)
				printf("Value is the BST\n");
				else if(key==NULL)
				printf("Value is not in the BST\n");
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}
