#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>

using namespace std;

constexpr long long nanoseconds = 1000000000L;
void Merge_Sort(int* arr, int const begin, int const end);
void Merge(int* arr, int const left, int const mid, int const right);

int main()
{

    LARGE_INTEGER fr;
    QueryPerformanceFrequency(&fr);

    double freq = fr.QuadPart/1.0;
    long long total_time = 0;
    
    std:mt19937 gen(time(NULL));
    std::uniform_int_distribution<int> dist(-10, 100);

    static const int l=100000;
    int arr[l];


    for(int i=0; i<l; ++i)
    {
        arr[i]= dist(gen);
    }



    int one = dist(gen);

    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);
    for(int i=0; i<l; ++i)
    {
        if (arr[i] == one)
        {
            QueryPerformanceCounter(&end);
            total_time += end.QuadPart - start.QuadPart;
            cout << "Found!";
            break;
        }
    }

    cout << "\nTime: " << total_time/freq<< endl;

    return 0;
}
