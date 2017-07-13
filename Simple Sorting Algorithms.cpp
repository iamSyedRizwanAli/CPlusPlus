#include<iostream>
using namespace std;

void swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSorting(int * a, int size)
{
	if(size > 0)
	{
		if(size == 1)
		{
			if(a[0] > a[1])
				swap(a[0], a[1]);
		}
		else
		{
			bubbleSorting(a , size - 1);
			if(a[size - 2] > a[size - 1])
				swap(a[size - 1], a[size - 2]);
		}
	}
}

void bubbleSort(int * a, int size)
{
	if(size > 0)
	{
		bubbleSorting(a, size - 1);
		bubbleSort(a, size - 1);
	}
}

int findLowestIndex(int * a, int start, int end)
{
	if(start <= end && start > -1 && end > -1)
	{
		if(start == end -1)
		{
			if(a[start] < a[end])
				return start;
			else
				return end;
		}
		else
		{
			int ind = findLowestIndex(a, start + 1, end);
						
			if(a[start] < a[ind])
				return start;
			else
				return ind;
		}
	}
	return 0;
}

void selectionSorting(int * a, int start, int end)
{
	if(start < end)
	{
		int ind = findLowestIndex(a, start, end);
		swap(a[start], a[ind]);
		selectionSorting(a, start + 1, end);		
	}
}

void selectionSort(int * a, int start, int end)
{
	if(start < end)
	{
		selectionSorting(a, start, end);
		selectionSort(a, start + 1, end);
	}
}

void insertionsorting(int * arr, int start, int end, int temp)
{
	if(start > 0)
	{
		if(arr[start - 1] > temp)
		{
			arr[start] = arr[start - 1];
		}		
		insertionsorting(arr, start -1, end, temp);
		if(arr[start - 1] > temp)
		{
			arr[start] = arr[start - 1];
		}
	}
}

void insertionSwaping(int * arr, int start, int end)
{
	int j = start + 1;
	int temp = arr[j];
	while(j > 0 && temp < arr[j-1])
	{
		arr[j] = arr[j-1];
		j--;
	}
	arr[j] = temp;
}

void insertionsort(int * arr, int start, int end)
{
	if(start < end)
	{
		/*int j = start + 1;
		int temp = arr[j];
		while(j > 0 && temp < arr[j-1])
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = temp;*/
		insertionSwaping(arr, start, end);
		insertionsort(arr, start + 1, end);
	}
}

void main()
{
	int a[6] = {6,3,7,9,4,8};
	insertionsort(a, 0, 5);
	
	for(int i = 0 ; i < 6 ; i++)
		cout << a[i] << ' ';

}