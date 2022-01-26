#include <iostream>

using namespace std; /// Descending

void Merge(int arr[], int const left, int const mid, int const right);
void Merge_Sort(int* arr, int const begin, int const end);
void display(int* arr, int n);

int main()
{
	int arr[7] = { 11, 2, 48, 13, 9, 5, 21 };

	cout << "\nUnsorted array:  ";
	display(arr, 7);

	Merge_Sort(arr, 0, 6);

	cout << "\n\nSorted array:  ";
	display(arr, 7);

	puts("\n\n");
	return 0;
}

void Merge_Sort(int* arr, int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	Merge_Sort(arr, begin, mid);
	Merge_Sort(arr, mid + 1, end);
	Merge(arr, begin, mid, end);
}

void Merge(int arr[], int const left, int const mid, int const right)
{
	int Number_elements_subArrayOne = mid - left + 1;
	int Number_elements_subArray_two = right - mid;

	int* leftArray = new int[Number_elements_subArrayOne];
	int* rightArray = new int[Number_elements_subArray_two];

	for (int i = 0; i < Number_elements_subArrayOne; ++i)
		leftArray[i] = arr[left + i];
	for (int j = 0; j < Number_elements_subArray_two; ++j)
		rightArray[j] = arr[mid + 1 + j];

	int index_leftArray = 0;
	int index_rightArray = 0;
	int index_MergedAray = left;

	while (index_leftArray < Number_elements_subArrayOne && index_rightArray < Number_elements_subArray_two)
	{
		if (leftArray[index_leftArray] >= rightArray[index_rightArray])
		{
			arr[index_MergedAray] = leftArray[index_leftArray];
			++index_leftArray;
		}
		else
		{
			arr[index_MergedAray] = rightArray[index_rightArray];
			++index_rightArray;
		}

		++index_MergedAray;
	}

	///Any leftovers in either left o right array

	while (index_leftArray < Number_elements_subArrayOne)
	{
		arr[index_MergedAray] = leftArray[index_leftArray];
		++index_leftArray;
		++index_MergedAray;
	}

	while (index_rightArray < Number_elements_subArray_two)
	{
		arr[index_MergedAray] = rightArray[index_rightArray];
		++index_rightArray;
		++index_MergedAray;
	}
}


void display(int* arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
}
