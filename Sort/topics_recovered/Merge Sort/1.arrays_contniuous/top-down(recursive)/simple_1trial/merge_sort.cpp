#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

void MergeSort(int* arr, int const begin, int const end);
void Merge(int* arr, int const left, int const mid, int const right);
void display(int* arr, int n);

int main()
{
    srand(time(NULL));
    int n;
    cout << "\nEnter the size: ";
    cin >> n;

    int* arr = new int[n];

    for(int i=0; i<n; ++i)
    {
        arr[i] = rand() % 101;
    }

    cout << "\nUnsorted array: ";
    display(arr, n);

    MergeSort(arr, 0, n-1);

    cout << "\n\nSorted array: ";
    display(arr, n);

    return 0;
}

void MergeSort(int* arr, int const begin, int const end)
{
    if(begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, begin, mid, end);
}

void Merge(int* arr, int const left, int const mid, int const right)
{
    int num_sub_arr1 = mid - left + 1;
    int num_sub_arr2 = right - mid;

    int* leftArray = new int[num_sub_arr1];
    int* rightArray = new int[num_sub_arr2];

    for(int i=0; i<num_sub_arr1; ++i)
        leftArray[i] = arr[left+i];

    for(int i=0; i<num_sub_arr2; ++i)
        rightArray[i] = arr[mid+1 + 1];
    
    int index_sub_arra1 = 0;
    int index_sub_array2 = 0;
    int index_merged_array = left;

    //let the hacking begin...

    while (index_sub_arra1 < num_sub_arr1 && index_sub_array2 < num_sub_arr2)
    {
        if(leftArray[index_sub_arra1] <= rightArray[index_sub_array2])
        {
            arr[index_merged_array] = leftArray[index_sub_arra1];
            ++index_sub_arra1;
        }
        else
        {
            arr[index_merged_array] = rightArray[index_sub_array2];
            ++index_sub_array2;
        }
        ++index_merged_array;

        // in the case when one of the parts have some leftovers...

        while (index_sub_arra1 < num_sub_arr1)
        {
            arr[index_merged_array] = leftArray[index_sub_arra1];
            ++index_sub_arra1;
            ++index_merged_array;
        }

        //if any leftovers for right array

        while (index_sub_array2 < num_sub_arr2)
        {
            arr[index_merged_array] = rightArray[index_sub_array2];
            ++index_sub_array2;
            ++index_merged_array;
        }
        
        
    }
    
}

void display(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    
}