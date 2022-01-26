#include <iostream>
#include <random>

using namespace std;


int main()
{
    std::random_device rd;
    cout << rd() << endl;
    std:mt19937 gen(rd());
    //mercand twister 

    std::uniform_int_distribution<int> dist(-100, 100);

    for(int i=0; i<10; ++i)
    {
        cout << dist(gen) << endl;
    }

    return 0;
}