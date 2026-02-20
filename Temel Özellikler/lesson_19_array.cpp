#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int main ()
{
    string cars[5] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
    for (int i = 0; i < 5; i++) 
    {
        cout << i << " = " << cars[i] << "\n";
    }
}