#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
}*f=NULL,*r=NULL;
void enqueue(int);
void dequeue();
void display();
main()
{
	int option,val;
	printf("Queue using Linked List\n");
	while(1)
	{
		printf("1.Enqueue\t2.Dqueue\t3.Display\t4.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the Value:");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}
void enqueue(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=val;
	newnode->next=NULL;
	if(f==NULL&&r==NULL)
	{
		f=newnode;
		r=newnode;
	}
	else
	{
		r->next=newnode;
		r=newnode;
	}
	printf("Node Inserted\n");
}
void dequeue()
{
	if(f==NULL||r==NULL)
		printf("Queue is underflow\n");
	else
	{
		struct node *t=f;
		f=f->next;
		printf("Dequeue value:%d\n",t->data);
		free(t);
		printf("New Queue:");
		display();
	}
}
void display()
{
	if(f==NULL&&r==NULL)
	printf("Queue is underflow\n");
	else
	{
		struct node *t=f;
		while(t!=NULL)
		{
			printf("%d-->",t->data);
			t=t->next;
		}
		printf("NULL\n");
	}
}
