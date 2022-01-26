

#include <iostream>

using namespace std;

void display(int* arr, int n);
void Merge(int* arr, int const left, int const mid, int const right);
void Merge_Sort(int* arr, int const begin, int const end);

int main()
{
    int arr[5] = {11, 2, 48, 13, 9};
    cout << "\nUnsorted array:  ";
    display(arr, 5);

    Merge_Sort(arr, 0, 4);

    cout << "\n\nSorted array:  ";
    display(arr, 5);



    puts("\n\n");
    return 0;
}

void display(int* arr, int n)
{
    for (int i=0; i<n; ++i)
    {
        cout << arr[i] << "  ";
    }
}


void Merge_Sort(int* arr, int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end-begin) / 2;
    Merge_Sort(arr, begin, mid);   /// LEFT subarray 0 -> mid   including mid
    Merge_Sort(arr, mid+1, end);   /// RIGHT subarray mid+1 -> end including end
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

