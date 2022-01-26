

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

void swapp(int* arr, int i, int pIndex);
int Partition(int* arr, int const left, int const right);
void QuickSort(int* arr, int const begin, int const end);

int main()
{
	int arr[] = { 2, 11, 48, 13, 9, 21, 4, 3};


	cout << "\n\nUnsorted array:  ";
	for(int i=0; i<8; ++i)
		cout << arr[i] << "  ";

	//QuickSort(arr, 0, 8 - 1);

	assert(is_sorted(arr, arr+ 8));

	cout << "\n\nSorted array:  ";
	for(int i=0; i<8; ++i)
		cout << arr[i] << "  ";

	puts("\n\n\n");
	return 0;
}

void QuickSort(int* arr, int const begin, int const end)
{
	if (begin >= end)
		return;
	int pIndex = Partition(arr, begin, end);

	QuickSort(arr, begin, pIndex - 1);
	QuickSort(arr, pIndex + 1, end);
}

int Partition(int* arr, int const left, int const right)
{
	int pivot = arr[left];
	int pIndex = left;

	for (size_t i = left+1; i <= right; ++i)
	{
		if (arr[i] <= pivot)
		{
			++pIndex;
			if ( i != pIndex)
				swapp(arr, i, pIndex);
		}
	}

	swapp(arr, left, pIndex);
	return pIndex;
}

void swapp(int* arr, int i, int pIndex)
{
	int temp = arr[pIndex];
	arr[pIndex] = arr[i];
	arr[i] = temp;
}



