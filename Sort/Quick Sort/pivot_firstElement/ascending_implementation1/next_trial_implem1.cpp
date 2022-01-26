

#include <iostream>

using namespace std;

void display(int* arr, int n);
void swapp(int* arr, int i, int pIndex);
int Partition(int* arr, int const left, int const right);
void QuickSort(int* arr, int const begin, int const end);

int main()
{
    int arr[7] = {9, 48, 2, 13, 21, 4, 11};

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

int Partition(int* arr, int const left, int const right)
{
    int pivot = arr[left];
    int pIndex = left+1;

    for(size_t i=left+1; i<= right; ++i)
    {
        if (arr[i] <= pivot)
        {
            if ( i != pIndex)
                swapp(arr, i, pIndex);
            ++pIndex;
        }
    }

    swapp(arr, left, pIndex-1);
    return pIndex-1;   
}

void swapp(int* arr, int i, int pIndex)
{
    int temp =  arr[pIndex];
    arr[pIndex] = arr[i];
    arr[i] = temp;
}

void display(int* arr, int n)
{
    for(int i=0; i<n; ++i)
        cout << arr[i] << "  ";
}