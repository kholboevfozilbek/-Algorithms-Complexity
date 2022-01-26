#include <iostream>

using namespace std;

void MergeSort(int* arr, int const begin, int const end);
void Merge(int* arr, int left, int mid, int right);
void display(int* arr, int n);

int main()
{
    int arr[] = {11, 8, 2, 9, 3, 7};
    cout << "\nUnsorted array: ";
    display(arr, 6);

    MergeSort(arr, 0, 5);

    cout << "\nSorted array: ";
    display(arr, 6);
    cout << endl << endl;

    return 0;
}

void display(int* arr, int n)
{
    for(auto i=0; i<n; ++i)
        cout << arr[i] << "  ";
}

void MergeSort(int* arr, int const begin, int const end)
{
    if(begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, begin, mid, end);
}

void Merge(int* arr, int left, int mid, int right)
{
    int subarrone = mid - left + 1;
    int subarrtwo = right - mid;

    int* left_temp = new int[subarrone];
    int* right_temp = new int[subarrtwo];

    for(auto i=0; i<subarrone; ++i)
        left_temp[i] = arr[left + i];
    for(auto j=0; j<subarrtwo; ++j)
        right_temp[j] = arr[mid+1 + j];

    auto index_sub_arr1 = 0, index_sub_arr2 = 0;
    int index_merged_arr = left;

    //let the hacking begin...
    while (index_sub_arr1 < subarrone && index_sub_arr2 < subarrtwo)
    {
        if(left_temp[index_sub_arr1] <= right_temp[index_sub_arr2])
        {
            arr[index_merged_arr] = left_temp[index_sub_arr1];
            index_sub_arr1++;
        }
        else
        {
            arr[index_merged_arr] = right_temp[index_sub_arr2];
            ++index_sub_arr2;
        }
        ++index_merged_arr;
    }

    //for leftovers in either of left or right arrays
        while (index_sub_arr1 <subarrone)
        {
            arr[index_merged_arr] = left_temp[index_sub_arr1];
            index_sub_arr1++;
             ++index_merged_arr;
        }

        while (index_sub_arr2 <subarrtwo)
        {
            arr[index_merged_arr] = right_temp[index_sub_arr2];
            index_sub_arr2++;
             ++index_merged_arr;
        }




}
