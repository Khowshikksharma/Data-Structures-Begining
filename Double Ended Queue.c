#include <stdio.h>
#include <stdlib.h>
#define size 5
int dq[size];
int f=-1,r=-1;
void insert_front(int val)
{
	if((f==0&&(r=size-1))||(f==r-1))
		printf("Queue is Overflow\n");
	else if(f==-1&&r==-1)
	{
		f=r=0;
		dq[f]=val;
	}
	else if(f==0)
	{
		f=size-1;
		dq[f]=val;
	}
	else
	{
		f--;
		dq[f]=val;
	}
}
void insert_rear(int val)
{
	if((f==0&&r==size-1)||(f==r+1))
		printf("Queue is overflow\n");
	else if(f==-1&&r==-1)
		dq[++r]=val;
	else if(r==size-1){
		r=0;
		dq[r]=val;
	}
	else
		dq[++r]=val;
}
void display()
{
	int i=f;
	printf("Elements in double ended queue:\n");
	while(i!=r)
	{
		printf("%d ",dq[i]);
		i=(i+1)%size;
	}
	printf("%d\n",dq[r]);
}
void delete_front()
{
	if(f==-1&&r==-1)
		printf("Double ended queue is empty\n");
	else if(f==r)
	{
		printf("Deleted element:%d\n",dq[f]);
		f=r=-1;
	}
	else if(f==size-1)
	{
		printf("Deleted element:%d\n",dq[f]);
		f=0;
	}
	else
		printf("Deleted elemnt%d\n",dq[f++]);
}
void delete_rear()
{
	if(f==-1&&r==-1)
		printf("Double ended queue is empty\n");
	else if(f==r)
	{
		printf("Deleted element:%d\n",dq[f]);
		f=r=-1;
	}
	else if(r==0)
	{
		printf("Deleted element:%d\n",dq[r]);
		r=size-1;
	}
	else
		printf("Deleted elemnt%d\n",dq[r--]);
}
main()
{
	int option,val;
	printf("***Double Ended Queue***\n");
	while(1)
	{
		printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&val);
				insert_front(val);
				break;
			case 2:
				printf("Enter the value:");
				scanf("%d",&val);
				insert_rear(val);
				break;
			case 3:
				delete_front();
				break;
			case 4:
				delete_rear();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
		}
	}
	return 0;
}
