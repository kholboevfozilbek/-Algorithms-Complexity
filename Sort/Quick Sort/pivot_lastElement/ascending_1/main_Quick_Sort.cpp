

#include <iostream>

using namespace std;

void display(int* arr, int n);
void swap(int* arr, int i, int pIndex);
void QuickSort(int* arr, int const begin, int const end);
int Partition(int* arr, int left, int right);

int main()
{
    int arr[7] = {11, 2, 48, 13, 9, 21, 7};

    cout << "\n\nUnsorted array:  ";
    display(arr, 7);

    QuickSort(arr, 0, 6);

    cout << "\n\nSorted array:  ";
    display(arr, 7);

    puts("\n\n");
    return 0;
}

void QuickSort(int* arr, int const begin, int const end)
{
    if (begin >= end)
        return;
    int pIndex = Partition(arr, begin, end);

    QuickSort(arr, begin, pIndex-1);
    QuickSort(arr, pIndex+1, end);
}

int Partition(int* arr, int left, int right)
{
    int pivot = arr[right];
    int pIndex = left;

    for(int i=left; i<right; ++i)
    {
        if (arr[i] <= pivot)
        {
            swap(arr, i, pIndex);
            ++pIndex;
        }
    }

    swap(arr, right, pIndex);
    return pIndex;
}

void swap(int* arr, int i, int pIndex)
{
    int temp = arr[pIndex];
    arr[pIndex] = arr[i];
    arr[i] = temp;
}

void display(int* arr, int n)
{
    for(int i=0; i<n; ++i)
        cout << arr[i] << "  ";
}
