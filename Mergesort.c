#include <stdio.h>
void msort(int ,int);
void marray(int,int,int,int);
int a[100];
main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	msort(0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
void msort(int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		msort(l,m);
		msort(m+1,h);
		marray(l,m,m+1,h);
	}
}
void marray(int s,int b,int c,int d)
{
	int t[100];
	int i=s,j=c,k=0;
	while(i<=b && j<=d)
	{
		if(a[i]<a[j])
			t[k++]=a[i++];
		else
			t[k++]=a[j++];
	}
	while(i<=b)
		t[k++]=a[i++];
	while(j<=d)
		t[k++]=a[j++];
	for(i=s,j=0;i<=d;i++,j++)
		a[i]=t[j];
}
