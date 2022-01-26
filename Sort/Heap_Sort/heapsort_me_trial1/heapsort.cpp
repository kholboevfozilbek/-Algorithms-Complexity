
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using std::chrono::nanoseconds;

void Heapsort(int* arr, int n);
void heapify(int* arr, int n, int i);
void swapp(int* arr, int x, int y);
void display(int* arr, int n);

int main()
{
    std::random_device rd;
    std:mt19937 gen(time(NULL));
    std::uniform_int_distribution<int> dist(-100, 100);
    nanoseconds heap(0);

    int n = 100;
    int *arr = new int[n];

    for(int i=0; i<n; ++i)
        arr[i] = dist(gen);

    cout << "\n\nUnsorted array: ";
    display(arr, n);
    auto begin = std::chrono::steady_clock::now();
    Heapsort(arr, n);
    auto end = std::chrono::steady_clock::now();
    nanoseconds total(end - begin);
    heap = total;

    cout << "\n\nSorted array: ";
    display(arr, n);

    cout << "\n\nTotal time taken (nanoseconds):  " << heap.count()  << endl;


    puts("\n\n");
    return 0;
}


void Heapsort(int* arr, int n)
{
    for(int i= n/2 -1; i >= 0; --i)
        heapify(arr, n, i);
    
    for(int i= n-1; i >= 0; --i)
    {
        swapp(arr, 0, i);

        heapify(arr, i, 0);
    }
}

void heapify(int* arr, int n, int i)
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i)
    {
        swapp(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void swapp(int* arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void display(int* arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    
}