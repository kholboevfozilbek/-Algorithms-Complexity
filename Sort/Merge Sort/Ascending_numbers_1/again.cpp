#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Merge(int* arr, int const left, int const mid, int const right);
void MergeSort(int* arr, int start, int end);
void display(int* arr, int n);

int main()
{
    srand(time(nullptr));
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int* arr = new int[n];

    for(int i=0; i<n; ++i)
    {
        arr[i] = rand() % 101;
    }

    MergeSort(arr, 0, n-1);
    cout << "\n\nSorted Array: ";
    display(arr, n);

    

    return 0;
}

void MergeSort(int* arr, int const begin, int const end)
{
    if(begin >= end)
        return;
    int mid = begin + (end-begin) / 2;
    MergeSort(arr, begin, mid);   /// LEFT subarray 0 -> mid   including mid
    MergeSort(arr, mid+1, end);   /// RIGHT subarray mid+1 -> end including end
    Merge(arr, begin, mid, end);
}

void Merge(int* arr, int const left, int const mid, int const right)
{
    int subArrayOne = mid-left+1;
    int subArrayTwo = right - mid;

    int* leftArray  = new int[subArrayOne];
    int* rightArray = new int[subArrayTwo];

    for(int i=0; i<subArrayOne; ++i)
    {
        leftArray[i] = arr[left+i];
    }

    for(int j=0; j < subArrayTwo; ++j)
    {
        rightArray[j] = arr[mid+1+j];
    }

    int index_subArrayOne = 0;
    int index_subArrayTwo = 0;
    int index_MergedArray = left;

    /// let the hacking begin...
    while(index_subArrayOne < subArrayOne && index_subArrayTwo < subArrayTwo)
    {
        if (leftArray[index_subArrayOne] <= rightArray[index_subArrayTwo])
        {
            arr[index_MergedArray] = leftArray[index_subArrayOne];
            ++index_subArrayOne;
        }
        else
        {
            arr[index_MergedArray] = rightArray[index_subArrayTwo];
            ++index_subArrayTwo;
        }

        ++index_MergedArray;
    }

    /// For remaining elements in either leftArray or rightArray

    while(index_subArrayOne < subArrayOne)
    {
        arr[index_MergedArray] = leftArray[index_subArrayOne];
        ++index_subArrayOne;
        ++index_MergedArray;
    }

    while(index_subArrayTwo < subArrayTwo)
    {
        arr[index_MergedArray] = rightArray[index_subArrayTwo];
        ++index_subArrayTwo;
        ++index_MergedArray;
    }
}

void display(int* arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        cout << arr[i] << "  ";
    }
}