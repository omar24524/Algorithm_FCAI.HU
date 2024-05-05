#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp= *a;
	*a= *b;
	*b= temp;
}

#define HEAP_LEFT(i)   (2*i+1)
#define HEAP_RIGHT(i)  (2*i+2)
#define HEAP_PARENT(i) (i>>1)
void heap_max(int *heap, int count, int i)
{
	int l= HEAP_LEFT(i), r= HEAP_RIGHT(i), largest= i;
	if(l<count && heap[l]>heap[i])
		largest= l;
	if(r<count && heap[r]>heap[largest])
		largest= r;
	if(largest!=i)
	{
		swap(heap+i, heap+largest);
		heap_max(heap, count, largest);
	}
}
int* heap_sort(int *arr, int count)
{
	for(int i=(count>>1)-1;i>=0;i--)
		heap_max(arr, count, i);
	for(int i=count-1;i>0;i--)
	{
		swap(arr, arr+i);
		heap_max(arr, i, 0);
	}
	return arr;
}
int* ssort(int *arr, int n)
{	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
				swap(arr+i, arr+j);
		}
	}
	return arr;
}
int* wigglePermute(int *arr, int n)
{
	int i= 0, j= 0, k= n-1;
	// ssort(arr, n);
	heap_sort(arr, n);
	int mid= arr[n>>1];
#define ARR(IDX) arr[((IDX)*2+1)%(n|1)]
	while(j<=k)
	{
		if(ARR(j)>mid)
			swap(&ARR(i++), &ARR(j++));
		else if(ARR(j)<mid)
			swap(&ARR(j), &ARR(k--));
		else
			j++;
	}
#undef ARR
	return arr;
}
int main(int argc, char **argv)
{
	int arr[]= {0, 1, 2, 3};
	int n= _countof(arr);
	wigglePermute(arr, n);
	for(size_t i=0;i<n;i++)
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}
