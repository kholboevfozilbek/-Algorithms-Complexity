
#include <iostream>

using namespace std;


int min(int a, int b);
void MergeSort(int* arr, int n);
void Merge(int* arr, int const left, int const mid, int const right);
void display(int* arr, int n);

int main()
{
    int arr[] = {11, 2, 45, 9, 1, 13, 5, 3};

    cout << "\n\nUnsorted elements:  ";
    display(arr, 8);

    MergeSort(arr, 8);

    cout << "\n\nSorted elements:  ";
    display(arr, 8);

    return 0;
}

void MergeSort(int* arr, int n)
{
    int curr_size;
    int left_start_index;

    for(int curr_size=1; curr_size <= n-1; curr_size = curr_size*2)
    {
        for(left_start_index=0; left_start_index < n-1; left_start_index += curr_size*2)
        {
            int mid  = min(left_start_index + curr_size - 1, n-1);
            int rightend = min(left_start_index + 2*curr_size - 1, n-1);
            Merge(arr, left_start_index, mid, rightend);
        }
    }
}

void Merge(int* arr, int const left, int const mid, int const right)
{
    int number_subArrayOne = mid - left + 1;
    int number_subArrayTwo = right -  mid;

    int* leftSubArray = new int[number_subArrayOne];
    int* rightSubArray = new int[number_subArrayTwo];

    for(int i=0; i<number_subArrayOne; ++i)
        leftSubArray[i] = arr[left + i];
    for(int j=0; j < number_subArrayTwo; ++j)
        rightSubArray[j] = arr[mid+1 + j];

    int index_leftArray = 0;
    int index_rightArray = 0;
    int index_Merged_Array = left;

    while (index_leftArray < number_subArrayOne && index_rightArray < number_subArrayTwo)
    {
        if(leftSubArray[index_leftArray] <= rightSubArray[index_rightArray] )
        {
            arr[index_Merged_Array] = leftSubArray[index_leftArray];
            ++index_leftArray;
        }
        else
        {
            arr[index_Merged_Array] = rightSubArray[index_rightArray];
            ++index_rightArray;
        }
        ++index_Merged_Array;
    }

    while (index_leftArray < number_subArrayOne)
    {
        arr[index_Merged_Array] = leftSubArray[index_leftArray];
        ++index_leftArray;
        ++index_Merged_Array;
    }

    while (index_rightArray < number_subArrayTwo)
    {
        arr[index_Merged_Array] = rightSubArray[index_rightArray];
        ++index_rightArray;
        ++index_Merged_Array;
    }
    
}

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

void display(int* arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        cout << arr[i] << "  ";
    }
}