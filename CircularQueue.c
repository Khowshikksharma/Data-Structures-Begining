#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size];
int front=-1,rear=-1;
void enqueue(int);
void dequeue();
void display();
main()
{
	int option,val;
	printf("Circular Queue\n");
	while(1)
	{	printf("\t***MENU***\n");
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value:");
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
	if(front==-1&&rear==-1)
	{
		front++;
		q[++rear]=val;
	}
	else if((rear+1)%size==front)
		printf("Queue is overflow\n");
	else
	{
		rear=(rear+1)%size;
		q[rear]=val;
	}
}
void dequeue()
{
	if(front==-1&&rear==-1)	
		printf("Queue is underflow\n");
	else if(front==rear)
	{
		printf("The dequed element is %d\n",q[front]);
		front=rear=-1;
	}
	else
	{
		printf("The dequed element is %d\n",q[front]);
		front=(front+1)%size;
	}
}
void display()
{
	if(front==-1&&rear==-1){
		printf("Queue is empty");
	}
	else{
		while(front<=rear){
			printf("%d\t",q[front]);
			front=(front+1)%size;
		}
	}
}
