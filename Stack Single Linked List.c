#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
}*top=NULL;
void push(int);
void pop();
void display();
main()
{
	int option,val;
	printf("Stack using Linked list\n");
	while(1)
	{
		printf("1.Push\t2.Pop\t3.Display\t4.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				pop();
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
void push(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=val;
	newnode->next=NULL;
	if(top==NULL)
		top=newnode;
	else
	{
		newnode->next=top;
		top=newnode;
	}
	printf("Node Inserted\n");
}
void pop()
{
	struct node *t=top;
	if(top==NULL)
		printf("Stack is underflow\n");
	else
	{
		top=top->next;
		printf("Poped Value:%d\n",t->data);
		free(t);
		printf("New Stack:");
		display();
	}
}
void display()
{
	if(top==NULL)
		printf("Stack is empty\n");
	else
	{
		struct node *t=top;
		while(t!=NULL)
		{
			printf("%d-->",t->data);
			t=t->next;
		}
		printf("NULL\n");
	}
}
