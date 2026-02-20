#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int main ()
{
    selamlama();

    int i;
    for (i = 0; i < 6; i++)
    {
        if ( i == 3)
        {
            continue;
        }
        cout << i << endl;
    }
    veda();   
    return 0;
}