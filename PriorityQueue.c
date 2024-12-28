#include <stdio.h>
#include <stdlib.h>
struct node{
	int priority,data;
	struct node *next;
}*front=NULL;
void insert(int val,int priority)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->priority=priority;
	newnode->next=NULL;
	if(front==NULL)
	{
		newnode->next=front;
		front=newnode;
	}
	else
	{
		temp=front;
		while(temp->next!=NULL&&temp->next->priority<=priority)
			temp=temp->next;
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void delete()
{
	struct node *temp;
	if(front==NULL)
		printf("Queue is underflow\n");
	else
	{
		temp=front;
		printf("Deleted node:%d\n",temp->data);
		front=front->next;
		free(temp);
	}
}
void display()
{
	if(front==NULL)
		printf("queue is underflow\n");
	else
	{
		struct node *t=front;
		printf("Data\tPriority\n");
		while(t!=NULL)
		{
			printf("%d\t%d\n",t->data,t->priority);
			t=t->next;
		}
	}
}
main()
{
	int option,val,priority;
	printf("****Priority Queue****\n");
	while(1)
	{
		printf("***MENU***\n");
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&val);
				printf("Enter the priority:");
				scanf("%d",&priority);
				insert(val,priority);
				break;
			case 2:
				delete();
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
