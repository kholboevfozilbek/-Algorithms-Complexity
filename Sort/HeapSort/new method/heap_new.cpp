

#include <iostream>
#include <assert.h>
#include <algorithm>

using namespace std;

void build_heap(int* arr, int size);
void maxheapify(int* arr, int i, int size);
void exchange(int* a, int* b);
void heapsort(int* arr, int size);
void display(int* arr, int len);

int main()
{
    int arr[8] = {2, 12, 7, 48, 1, 5, 13, 7};

    cout << "\n\nunsoretd array: ";
    display(arr, 8);

    heapsort(arr, 8);

    assert(is_sorted(arr, arr+8));

    cout << "\n\nsorted array: ";
    display(arr, 8);

    return 0;
}

void heapsort(int* arr, int size)
{
    build_heap(arr, size);
    while(size > 1)
    {
        exchange(&arr[0], &arr[size-1]);
        --size;
        maxheapify(arr, 0, size);
    }
}

void build_heap(int* arr, int size)
{
    for(int i= (size-2) / 2; i>=0; --i)
        maxheapify(arr, i, size);
}

void maxheapify(int* arr, int i, int size)
{
    int largest = i, left, right;
    left = 2*i + 1;
    right = 2*i + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        exchange(&arr[largest], &arr[i]);
        maxheapify(arr, largest, size);
    }

}

void exchange(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int* arr, int len)
{
    for(int i=0; i< len; ++i)
        cout << arr[i] << " ";

}
