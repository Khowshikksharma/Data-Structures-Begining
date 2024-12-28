#include <stdio.h>
#include <stdlib.h>
#define size 10
int ht[size];
void insert()
{
	int k,index,index1,i;
	printf("Enter the value:");
	scanf("%d",&k);
	index=k%size;
	for(i=0;i<size;i++)
	{
		index1=(index+i*i)%size;
		if(ht[index1]==-1)
		{
			ht[index1]=k;
			break;
		}
	}
	if(i==size)
		printf("Element cannot be inserted\n");
}
void search()
{
	int key,index,flag=0,i,hkey;
	printf("Enter the value:");
	scanf("%d",&key);
	hkey=key%size;
	for(i=0;i<size;i++)
	{
		index=(hkey+i*i)%size;
		if(ht[index]==key)
		{
			printf("Value found at index &%d\n",i);
			break;
		}
	}
	if(i==size)
		printf("Value not found\n");
}
void display()
{
	int i;
	printf("Elemnts in the hashtable:\n");
	for(i=0;i<size;i++)
		printf("at index %d\tValue:%d\n",i,ht[i]);
}
main()
{
	int i;
	for(i=0;i<size;i++)
		ht[i]=-1;
	int option;
	while(1)
	{
		printf("1.Insert\n2.Search\n3.Display\n4.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				insert();
				break;
			case 2:
				search();
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
