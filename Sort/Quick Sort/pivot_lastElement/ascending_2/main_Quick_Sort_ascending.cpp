

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void display(int* arr, int n);
void swap(int* arr, int i, int pIndex);
int Partition(int* arr, int left , int right);
void QuickSort(int* arr, int const begin, int const end);

int main()
{
    srand(time(nullptr));
    int arr[6] = {1, 2, 3, 4, 5, 6};


    cout << "\n\nUnsorted array:  ";
    display(arr, 6);

    QuickSort(arr, 0, 6-1);

    cout << "\n\nSorted array:  ";
    display(arr, 6);

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

int Partition(int* arr, int left , int right)
{
    int pivot = arr[right];
    int pIndex = left;

    for(int i=left; i<right; ++i)
    {
        if (arr[i] <= pivot)
        {
            if (i != pIndex)
                swap(arr, i, pIndex);
            ++pIndex;
        }
    }

    if (right != pIndex)
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
    {
        if (i == 20 || i == 40 || i == 60)
            cout << "\n\t\t";
        cout << arr[i] << "  ";

    }


}



