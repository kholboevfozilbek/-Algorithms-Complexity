

#include <iostream>
#include "library_objects.h"

using namespace std;


template<typename T>
void display(T* arr, int n);

template<typename T>
void Insertion_Sort(T* arr, int n);

int main()
{
    Company arr[3];
    Company Tesla("Elon Musk", "Car Manufacturer", 1997, 300);
    Company Microsoft("Bill Gates", "Computer Hardware and Software", 1986, 120);
    Company Apple("Tim Cook", "Mobile and Laptop", 1978, 500);

    arr[0] = Apple;
    arr[1] = Tesla;
    arr[2] = Microsoft;

    cout << "\nUnsorted array: ";
    display(arr, 3);


    Insertion_Sort(arr, 3);

    cout << "\n\n----------------------------\n";
    cout << "Sorted Ascending order:  ";
    display(arr, 3);

    return 0;
}


template<typename T>
void Insertion_Sort(T* arr, int n)
{
    for (int i=1; i<n; ++i)
    {
        T value = arr[i];
        int hole = i;

        while(hole > 0 && arr[hole-1] > value)
        {
            arr[hole] = arr[hole-1];
            --hole;
        }

        if (hole != i)
            arr[hole] = value;
    }
}

template<typename T>
void display(T* arr, int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << "\n---------------------------\n";
}
