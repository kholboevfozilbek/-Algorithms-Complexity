

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void display(int* arr, int n);

int main()
{
    srand(time(nullptr));
    int arr[20];

    for (int i=0; i<20; ++i)
    {
        arr[i] = rand() % 123;
    }

    cout << "\nunsorted array:  ";
    display(arr, 20);



    puts("\n\n");
    return 0;
}


void display(int* arr, int n)
{
    for (int i=0; i<n; ++i)
        cout <<  arr[i] << "  ";
}
