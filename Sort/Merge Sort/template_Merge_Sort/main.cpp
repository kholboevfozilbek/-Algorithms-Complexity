#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

template<typename T>
void Merge(T* arr, int const left, int const mid, int const right);

template<typename T>
void Merge_Sort(T* arr, int const begin, int const end);

template<typename T>
void display(T* arr, int n);



int main()
{
    int const n = 10;
    srand(time(nullptr));
    int arr[n];

    for(int i=0; i<n; ++i)
        arr[i] = rand() % 150;

    cout << "\n\nUnsorted Array:  ";
    display(arr, 10);
    Merge_Sort(arr, 0, n-1);

    cout << "\n\nSorted array:  ";
    display(arr, 10);

    puts("\n\n");
    return 0;
}

template<typename T>
void Merge_Sort(T* arr, int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;

    Merge_Sort(arr, begin, mid);
    Merge_Sort(arr, mid+1, end);
    Merge(arr, begin, mid, end);
}

template<typename T>
void Merge(T* arr, int const left, int const mid, int const right)
{
    int const Number_SubArrayOne = mid-left+1;
    int const Number_SubArrayTwo = right - mid;

    T* leftArray = new T[Number_SubArrayOne];
    T* rightArray = new T[Number_SubArrayTwo];

    for (size_t i = 0; i < Number_SubArrayOne; ++i)
        leftArray[i] = arr[left+i];

    for(int j=0; j<Number_SubArrayTwo; ++j)
        rightArray[j] = arr[mid+1+j];

    int index_SubArrayOne = 0;
    int index_SubArrayTwo  = 0;
    int index_MergedArray = left;


    while(index_SubArrayOne < Number_SubArrayOne && index_SubArrayTwo < Number_SubArrayTwo)
    {
        if (leftArray[index_SubArrayOne] <= rightArray[index_SubArrayTwo])
        {
            arr[index_MergedArray] = leftArray[index_SubArrayOne];
            ++index_SubArrayOne;
        }
        else
        {
            arr[index_MergedArray] = rightArray[index_SubArrayTwo];
            ++index_SubArrayTwo;
        }

        ++index_MergedArray;
    }


    /// For any leftovers in either left & right arrays

    while (index_SubArrayOne < Number_SubArrayOne )
    {
        arr[index_MergedArray] = leftArray[index_SubArrayOne];
        ++index_SubArrayOne;
        ++index_MergedArray;
    }

    while (index_SubArrayTwo < Number_SubArrayTwo)
    {
        arr[index_MergedArray] = rightArray[index_SubArrayTwo];
        ++index_SubArrayTwo;
        ++index_MergedArray;
    }

}

template<typename T>
void display(T* arr, int n)
{
    for(int i=0; i<n; ++i)
        cout << arr[i] << "  ";
}

