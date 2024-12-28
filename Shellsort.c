#include <stdio.h>
main()
{
	int n,i,j,temp,gap;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(gap=n/2;gap>0;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			for(j=i;j>=gap;j-g)
			{
				if(a[j]<a[j-gap])
				{
					temp=a[j];
					a[j]=a[j-gap];
					a[j-gap]=temp;
				}
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}
