#include <iostream>

using namespace std;

void Merge(int* arr, int const left, int const mid, int const right);
void display(int* arr, int n);
void iterative_Merge(int* arr, int n)
{
    for(int j=0; j<n; j+=2)
    {
        
        Merge(arr, j, j+1, j+2);
        break;
    }
}

int main()
{
    int arr[8] = {11, 2, 48, 13, 9, 2, 3, 5};
    iterative_Merge(arr, 8);
    display(arr, 8);
    return 0;
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