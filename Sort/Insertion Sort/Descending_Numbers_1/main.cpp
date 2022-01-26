

#include <iostream>

using namespace std;

void Insertion_Sort(int* arr, int n);
void display(int* arr, int n);


int main()
{
    int arr[6] = {11, 2, 48, 13, 9, 5};

    cout << "\nUnsorted array:  ";
    display(arr, 6);

    Insertion_Sort(arr, 6);

    cout << "\n\nSorted array:  ";
    display(arr, 6);

    puts("\n\n");
    return 0;
}

void Insertion_Sort(int* arr, int n)
{
    for (int i=1; i<n; ++i)
    {
        int value = arr[i];
        int hole = i;

        while(hole > 0 && arr[hole-1] < value)
        {
            arr[hole] = arr[hole-1];
            --hole;
        }

        if (hole != i)
            arr[hole] = value;
    }
}

void display(int* arr, int n)
{
    for (int i=0; i<n; ++i)
    {
        cout << arr[i] << "  ";
    }

}
