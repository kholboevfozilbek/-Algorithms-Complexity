

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;  /// Ascending


void Insertion_Sort(size_t* arr, int n);
void display(size_t* arr, int n);

int main()
{
    srand(time(nullptr));
    size_t arr[10000];

    for (int i=0; i<10000; ++i)
    {
        arr[i] = rand() % 12345678;
    }

    Insertion_Sort(arr, 10000);

    cout << "\n\nSorted array:  ";
    display(arr, 1000);

    return 0;
}

void Insertion_Sort(size_t* arr, int n)
{
    for (int i=1; i<n; ++i)
    {
        size_t value = arr[i];
        int hole = i;

        while(hole > 0 && arr[hole-1] > value)
        {
            arr[hole] = arr[hole-1];
            --hole;
        }

        if (hole != i);
            arr[hole] = value;
    }

}

void display(size_t* arr, int n)
{
    for (int i=0; i<n; ++i)
        cout <<  arr[i] << "  ";
}


