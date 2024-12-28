#include <stdio.h>
#include <stdlib.h>
#define size 10
struct node{
	int data;
	struct node *next;
}*ht[size];
void insert(int val)
{
	int i=val%size;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(ht[i]==NULL)
		ht[i]=newnode;
	else
	{
		struct node *t=ht[i];
		while(t->next!=NULL)
			t=t->next;
		t->next=newnode;
	}
}
void display()
{
	int i;
	for(i=0;i<size;i++)
	{
		if(ht[i]==NULL)
			printf("NULL\n");
		else
		{
			struct node *t=ht[i];
			while(t!=NULL)
			{
				printf("%d->",t->data);
				t=t->next;
			}
			printf("NULL\n");
		}
	}
}
main()
{
	int i;
	for(i=0;i<size;i++)
		ht[i]=NULL;
	int val,option;
	while(1)
	{
		printf("1.Create\n2.Display\n3.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&val);
				insert(val);
				break;
			case 2:
				display();
				break;
			case 3:
				exit(0);
		}
	}
	return 0;
}
