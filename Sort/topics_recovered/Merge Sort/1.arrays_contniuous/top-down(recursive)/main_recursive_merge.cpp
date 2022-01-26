

#include <iostream>
#include <stdexcept>
#include <random>
using namespace std;

void Merge_Sort(int* arr, int const begin, int const end);
void Merge(int* arr, int const left, int const mid, int const right);
void display(int* arr, int n);

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-100, 100);
    int* arr;
    int n;

    cout << "Enter the number of array: ";
    cin >> n;

    if(n <= 0)
        throw runtime_error("Please give valid length for array!");
    
    arr = new int[n];
    
    for(size_t i=0; i<n; ++i)
        arr[i] = dist(gen);

    cout << "\n\nUnsorted elements: \n";
    display(arr, n);

    Merge_Sort(arr, 0, n-1);

    cout << "\n\nSorted elements: \n";
    display(arr, n);

    delete[] arr;
    return 0;
}

void display(int* arr, int n)
{
    for(int i=0; i<n; ++i)
        cout << arr[i] << "  ";
}


void Merge_Sort(int* arr, int const begin, int const end)
{
    if(begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    Merge_Sort(arr, begin, mid); // LEFT
    Merge_Sort(arr, mid+1, end); // RIGHT
    Merge(arr, begin, mid, end);
    
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