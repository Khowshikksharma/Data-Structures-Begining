#include <stdio.h>
void qsort(int[] ,int ,int);
main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
void qsort(int a[],int first,int last)
{
	int i,j,temp,pivot;
	if(first<last)
	{
		pivot=i=first;
		j=last;
		while(i<j)
		{
			while(a[i]<=a[pivot] && i<last)
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else
			{
				temp=a[j];
				a[j]=a[pivot];
				a[pivot]=temp;
			}
		}
		qsort(a,first,j-1);
		qsort(a,j+1,last);
	}
}
