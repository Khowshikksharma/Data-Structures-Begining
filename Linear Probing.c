#include <stdio.h>
#include <stdlib.h>
#define size 10
int a[size];
void insert(int val)
{
	int i,index;
	for(i=0;i<size;i++)
	{
		index=((val%size)+i)%size;
		if(a[index]==-1)
		{
			a[index]=val;
			break;
		}
	}
}
void display()
{
	int i;
	for(i=0;i<size;i++)
		printf("%d\n",a[i]);
}
main()
{
	int i,val,option;
	for(i=0;i<size;i++)
		a[i]=-1;
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
