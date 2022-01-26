#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//Professor does not accept code with srand() rand() whatsover!

int main()
{
    srand(time(nullptr));
    for(int i=0; i<10; ++i)
    {
        cout << rand() << endl;
    }
    return 0;
}