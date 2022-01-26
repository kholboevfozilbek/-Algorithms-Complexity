

#include <iostream>
#include <vector>

using namespace std;

void display(int* arr, int n);
void swapp(int* arr, int i, int pIndex);
int Partition(int* arr, int left, int right);
void QuickSort(int* arr, int const begin, int const end);

int main()
{
    int arr[7] = {13, 2, 21, 7, 48, 9, 5};

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

    for(int i=left; i < right; ++i)
    {
        if (arr[i] <= pivot)
            {
                if (i != pIndex)
                    swapp(arr, i, pIndex);
                ++pIndex;
            }
    }

    swapp(arr, right, pIndex);
    return pIndex;
}

void swapp(int* arr, int i, int pIndex)
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
