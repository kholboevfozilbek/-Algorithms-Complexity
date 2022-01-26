
#include <vector>
#include <iostream>

using namespace std;

void swapp(vector<int> arr, int i, int pIndex);
int Partion(vector<int> arr, int const left, int const right);
void QuickSort(vector<int> arr, int const begin, int const end);
void display(vector<int> arr);

int main()
{
    vector<int> arr{ 2, 11, 48, 13, 9, 21, 4 };

    cout << "\n\nUnsorted elemenets: \n";
    display(arr);

    QuickSort(arr, 0, arr.size()-1);

    cout << "\n\nSorted elements: ";
    display(arr);

    return 0;
}

void QuickSort(vector<int> arr, int const begin, int const end)
{
    if(begin >= end)
        return;
    int pIndex =  Partion(arr, begin, end);
    QuickSort(arr, begin, pIndex-1);
    QuickSort(arr, pIndex+1, end);
}

int Partion(vector<int> arr, int const left, int const right)
{
    int pivot = arr[left];
    int pIndex = left+1;
    for(int i=left+1; i<=right; ++i)
    {
        if(arr[i] <= pivot)
        {
            if(pIndex != i)
            {
                swapp(arr, i, pIndex);
            }
            ++pIndex;
        }
    }

    swapp(arr, left, pIndex-1);
    return pIndex-1;
}

void swapp(vector<int> arr, int i, int pIndex)
{
	int temp = arr[pIndex];
	arr[pIndex] = arr[i];
	arr[i] = temp;
}

void display(vector<int> arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
		cout << arr[i] << "  ";
}