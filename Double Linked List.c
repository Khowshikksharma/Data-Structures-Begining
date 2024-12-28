#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*head=NULL;
void insert_at_first(int);
void insert_at_last(int);
void insert_at_position(int,int);
void delete_at_first();
void delete_at_last();
void delete_at_position(int);
void display();
void search(int);
void length();
main()
{
	int option,val,pos;
	printf("\tDoubly Linked List\n");
	while(1)
	{
		printf("1.Insert at first\n2.Insert at last\n3.Insert at position\n4.Delete at begin\n5.Delete at last\n6.Delete at positon\n7.Display\n8.Search\n9.Length\n10.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&val);
				insert_at_first(val);
				break;
			case 2:
				printf("Enter the value:");
				scanf("%d",&val);
				insert_at_last(val);
				break;
			case 3:
				printf("Enter the value:");
				scanf("%d",&val);
				printf("Enter the position:");
				scanf("%d",&pos);
				insert_at_position(val,pos);
				break;
			case 4:
				delete_at_first();
				break;
			case 5:
				delete_at_last();
				break;
			case 6:
				printf("Enter the position:");
				scanf("%d",&pos);
				delete_at_position(pos);
				break;
			case 7:
				display();
				break;
			case 8:
				printf("Enter the key:");
				scanf("%d",&val);
				search(val);  
				break;
			case 9:
				length();
				break;
			case 10:
				exit(0);
		}
	}
	return 0;
}
void insert_at_first(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
	printf("Node Inserted\n");
}
void insert_at_last(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		struct node *t=head;
		while(t->next!=NULL)
			t=t->next;
		t->next=newnode;
		newnode->prev=t;
	}
	printf("Node Inserted\n");
}
void insert_at_position(int val,int pos)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		int i;
		struct node *p=head,*f;
		for(i=1;i<pos;i++)
		{
			f=p;
			p=p->next;
		}
		f->next=newnode;
		newnode->prev=f;
		newnode->next=p;
		p->prev=newnode;
	}
	printf("Node Inserted\n");
}
void delete_at_first()
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		struct node *t=head;
		head=head->next;
		head->prev=NULL;
		printf("Deleted Node:%d\n",t->data);
		free(t);
		printf("New Linked list:");
		display();
	}
}
void delete_at_last()
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		struct node *p=head,*f;
		while(p->next!=NULL)
		{
			f=p;
			p=p->next;
		}
		f->next=NULL;
		printf("Deleted Node:%d\n",p->data);
		free(p);
		printf("New Linked list:");
		display();
	}
}
void delete_at_position(int pos)
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		int i;
		struct node *p=head,*f;
		for(i=1;i<pos;i++)
		{
			f=p;
			p=p->next;
		}
		f->next=p->next;
		(p->next)->prev=f;
		printf("Deleted node:%d\n",p->data);
		free(p);
		printf("New Linked list:");
		display();
	}
}
void display()
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		struct node *t=head;
		while(t!=NULL)
		{
			printf("%d<->",t->data);
			t=t->next;
		}
		printf("NULL\n");
	}
}
void search(int key)
{
	int flag=0;
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		struct node *t=head;
		while(t!=NULL)
		{
			if(t->data==key)
			{
				flag=1;
				break;
			}
			t=t->next;
		}
	}
	if(flag==1)
		printf("%d is in the linked list\n",key);
	else
		printf("%d is not in the linked list\n",key);
}
void length()
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		int count=0;
		struct node *t=head;
		while(t!=NULL)
		{
			count++;
			t=t->next;
		}
		printf("Length of linked list:%d\n",count);
	}
}
