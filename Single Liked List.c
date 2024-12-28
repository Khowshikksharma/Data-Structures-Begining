#include <stdio.h>
#include <stdlib.h>
void display(void);
void create(int);
void insertFirst(int);
void insertMiddle(int,int);
void deleteFirst(void);
void deleteMiddle(int);
void deleteLast(void);
void count(void);
void search(int);
struct node
{
	int data;
	struct node *next;
}*head=NULL;
main()
{
	int option,val,pos,k;
	while(1)
	{
		printf("1.Display\t2.Create\t3.insertFirst\t4.insertMiddle\t5.deleteFirst\n6.deleteMiddle\t7.deleteLast\t8.count \t9.search\tOthers Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				display();
				break;
			case 2:
				scanf("%d",&val);
				create(val);
				break;
			case 3:
				scanf("%d",&val);
				insertFirst(val);
				break;
			case 4:
				scanf("%d%d",&val,&pos);
				insertMiddle(val,pos);
				break;
			case 5:
				deleteFirst();
				break;
			case 6:
				scanf("%d",&pos);
				deleteMiddle(pos);
				break;
			case 7:
				deleteLast();
				break;
			case 8:
				count();
				break;
			case 9:
				scanf("%d",&k);
				search(k);
				break;
			default :
				exit(0);
		}
	}
	return 0;
}
void create(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		struct node *t=head;
		while(t->next!=NULL)
			t=t->next;
		t->next=newnode;
	}
}
void display()
{
	if(head==NULL)
	printf("Linked List is empty\n");
	else
	{
		struct node *t=head;
		while(t!=NULL)
		{
			printf("%d-->",t->data);
			t=t->next;
		}
		printf("NULL\n");
	}
}
void insertFirst(int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	head=newnode;
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void insertMiddle(int val,int pos)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	struct node *p=head,*f;
	int i;
	for(i=1;i<pos;i++)
	{
		f=p;
		p=p->next;
	}
	f->next=newnode;
	newnode->next=p;	
}
void deleteFirst()
{
	if(head==NULL)
	printf("Linked list is empty\n");
	else
	{
		struct node *t=head;
		head=head->next;
		printf("Deleted Node:%d\n",t->data);
		free(t);
	}
}
void deleteLast()
{
	if(head==NULL)
	printf("Linked list is empty\n");
	else
	{
		struct node *t=head;
		if(head->next==NULL)
		{ 
		  head=head->next;
		  free(t);
	    }
	    else
	    {
	    	struct node *p=head,*f;
	    	while(p->next!=NULL)
	    	{
	    		f=p;
	    		p=p->next;
			}
			f->next=NULL;
			free(p);
		}
	}
}
void deleteMiddle(int pos)
{
	int i;
	struct node *p=head,*f;		
	for(i=1;i<pos;i++)
	{
		f=p;
		p=p->next;
	}
	f->next=p->next;
	free(p);
}
void count()
{
	int c=0;
	struct node *p=head;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	printf("Count:%d\n",c);
}
void search(int k)
{
	int flag=0;
	if(head==NULL)
	printf("Linked list is empty\n");
	else
	{
		struct node *t=head;
		while(t!=NULL)
		{
			if(t->data==k)
			{
				flag=1;
				break;
		    }
		    t=t->next;
		}
	}
	if(flag==1)
	printf("%d is in the linked list\n",k);
	else
	printf("%d is not in the linked list\n",k);
}
