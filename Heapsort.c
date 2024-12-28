#include<stdio.h>
void max_heapify(int arr[], int n, int i)
{
	int t;
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest])
	largest = l;
	if (r < n && arr[r] > arr[largest])
	largest = r;
	if (largest != i)
	{
		t=arr[i];
		arr[i]=arr[largest];
		arr[largest]=t;
		max_heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	int i,t;
	for ( i = n / 2 - 1; i >= 0; i--)
		max_heapify(arr, n, i);
	for (i=n-1; i>=0; i--)
	{
		t=arr[i];
		arr[i]=arr[0];
		arr[0]=t;
		max_heapify(arr, i, 0);
	}
}
int main()
{
	int arr[100],n,i;
	printf("Enter number of nodes:\n");
	scanf("%d",&n);
	printf("Enter array elemets:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	heapSort(arr, n);
	printf("Sorted list:\n");
	for (i=0; i<n; ++i)
		printf("%3d",arr[i]);
}
