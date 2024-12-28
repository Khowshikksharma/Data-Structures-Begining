#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL,*tail=NULL;
void insert_at_first(int);
void insert_at_last(int);
void insert_at_pos(int,int);
void delete_at_first();
void delete_at_last();
void delete_at_pos(int);
void display();
void search(int);
void length();
main()
{
	int val,option,pos;
	while(1)
	{
		printf("1.Insert at first\t2.Insert at last\t3.Insert at position\t4.Delete at firsrt\t5.Delete at last\n6.Delete at position\t7.Display\t8.Search\t9.Length\t10.Exit\n");
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
				insert_at_pos(val,pos);
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
				delete_at_pos(pos);
				break;
			case 7:
				display();
				break;
			case 8:
				printf("Enter the value:");
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
}
void insert_at_first(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
		tail=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
		tail->next=head;
	}
	printf("Node Inserted\n");
}
void insert_at_last(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
		tail=newnode;
	}
	else
	{
		tail->next=newnode;
		tail=newnode;
		tail->next=head;
	}
	printf("Node Inserted\n");
}
void insert_at_pos(int val,int pos)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	int i;
	struct node *p=head,*f;
	for(i=1;i<pos;i++)
	{
		f=p;
		p=p->next;
	}
	f->next=newnode;
	newnode->next=p;
	printf("Node Inserted\n");
}
void delete_at_first()
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else if(head->next==head)
		head=NULL;
	else
	{
		struct node *t=head;
		head=head->next;
		tail->next=head;
		printf("Deleted node:%d\n",t->data);
		free(t);
	}
}
void delete_at_last()
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else if(head->next==head)
	{
		printf("Deleted Node:%d\n",head->data);
		head=NULL;
	}
	else
	{
		struct node *p=head,*f;
		while(p->next!=head)
		{
			f=p;
			p=p->next;
		}
		tail=f;
		tail->next=head;
		printf("Deleted Node:%d\n",p->data);
		free(p);
	}
}
void delete_at_pos(int pos)
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		struct node *p=head,*f;
		int i;
		for(i=1;i<pos;i++)
		{
			f=p;
			p=p->next;
		}
		f->next=p->next;
		printf("Deleted Node:%d\n",p->data);
		free(p);
	}
}
void display()
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		struct node *t=head;
		while(t->next!=head)
		{
			printf("%d->",t->data);
			t=t->next;
		}
		printf("%d\n",t->data);
	}
}
void search(int k)
{
	int flag=0;
	struct node *t=head;
	while(t->next!=head)
	{
		if(k==t->data)
		{
			flag=1;
			break;
		}
		t=t->next;
	}
	if(t->data==k)
		flag=1;
	if(flag==1)
		printf("%d is present in the linked list\n",k);
	else
		printf("%d is not present in the linked list\n",k);
}
void length()
{
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		int len=0;
		struct node *t=head;
		while(t->next!=head)
		{
			len++;
			t=t->next;
		}
		printf("Length of linked list:%d\n",len);
	}
}
