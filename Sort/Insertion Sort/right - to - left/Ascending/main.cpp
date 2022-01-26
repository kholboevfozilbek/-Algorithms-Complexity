


#include <iostream>
#define length 6

using namespace std;

void display(int* arr, int n);
void Insertion_Sort_backwards(int* arr, int n);

int main()
{
    int arr[6] = {11, 2, 48, 13, 9, 21};

    cout << "\nUnsorted array:  ";
    display(arr, length);

    Insertion_Sort_backwards(arr, length);

    cout << "\n\nSorted array:  ";
    display(arr, length);

    puts("\n\n");
    return 0;
}

void Insertion_Sort_backwards(int* arr, int n)
{
    for (int i=n-2; i >= 0; --i)
    {
        int value = arr[i];
        int hole = i;

        while(hole < n-1 && arr[hole+1] < value)
        {
            arr[hole] = arr[hole+1];
            ++hole;
        }

        if (hole != i)
            arr[hole] = value;
    }

}

void display(int* arr, int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << "  ";
}


