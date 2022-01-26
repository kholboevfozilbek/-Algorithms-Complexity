

#include <iostream>
#include <Windows.h>

using namespace std;

constexpr long long nanoseconds = 1000000000L;

void display(int* arr, int length);
void Selection_Sort(int* arr, int length);

int main()
{

    LARGE_INTEGER fr;
    QueryPerformanceFrequency(&fr);
    double freq = fr.QuadPart/1.0;
    long long total_time = 0;
    long times = 100;

    int arr[7] = {11, 2, 48, 13, 9, 5, 21};

    cout << "\nOur Unsorted elements:  ";
    display(arr, 7);

    for(int i=0; i<times; ++i)
    {
        LARGE_INTEGER start, end;
        QueryPerformanceCounter(&start);
        Selection_Sort(arr, 7);
        QueryPerformanceCounter(&end);
        total_time += end.QuadPart - start.QuadPart;
    }

    cout << "\nTime: " << total_time/freq/times << endl;

    cout << "\nOur sorted elements:  ";
    display(arr, 7);

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
