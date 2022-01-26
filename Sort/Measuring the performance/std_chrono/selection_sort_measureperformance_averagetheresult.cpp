

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

void display(int* arr, int length);
void Selection_Sort(int* arr, int length);

int main()
{
    static const int length = 1000;
    int arr[length];
    srand(time(nullptr));

    for (int i=0; i<length; ++i)
    {
        arr[i] = rand() % 150;
    }


    cout << "\nOur Unsorted elements:  ";
    display(arr, 10);

    chrono::nanoseconds total_time_taken(0);
    long times = 1000;
    for(int i=0; i< times; ++i)
    {
        auto start = chrono::steady_clock::now();

        Selection_Sort(arr, length);

        auto end = chrono::steady_clock::now();

        chrono::nanoseconds time_taken(end-start);
        total_time_taken += time_taken;
    }

    //cout << total_time_taken/times << endl; /// here why cout cannot output the chrono::nanoseconds

    cout << "\nOur sorted elements:  ";
    display(arr, 10);

    puts("\n");
    return 0;
}

void Selection_Sort(int* arr, int length)
{
    for (int i=0; i<length-1; ++i)
    {
        int small_index = i; int temp;

        for (int j=i+1; j<length; ++j) 
        {
            if (arr[j] < arr[small_index])
                small_index = j;
        }

        temp = arr[i]; 
        arr[i] = arr[small_index]; 
        arr[small_index] = temp; 
    }
}


void display(int* arr, int length)
{
    for (int i=0; i<length; ++i)
    {
        cout << arr[i] << " ";
    }
}

