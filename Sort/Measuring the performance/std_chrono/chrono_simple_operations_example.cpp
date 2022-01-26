#include <iostream>
#include <chrono>

using namespace std;

void Function()
{
    int a;
    a += 5;
    a*=20;
    a /= 2;
    a %= 5;
    a *= 9;
    if ( a % 2 == 0)
        cout << "Juft";
    else
        cout << "Toq" ;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    
    Function();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::nanoseconds time_taken(end-start);

    cout << "Timer took: " << time_taken.count()  << " nanoseconds " << endl;



    return 0;
}