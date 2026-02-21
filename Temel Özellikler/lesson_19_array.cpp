#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int main ()
{
    string car[5] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};
    string cars[5];
    cars[0] = "Volvo";
    cars[1] = "BMW";
    cars[2] = "Ford";
    cars[3] = "Mazda";
    cars[4] = "Tesla";
    for (int i = 0; i < 5; i++) 
    {
        cout << i << " = " << car[i] << "\n";

    }
    cout << endl << endl;
    for (int i = 0; i < 5; i++) 
    {
        cout << i << " = " << car[i] << "\n";
    }


    cout << "array length = " << (sizeof(car) / sizeof(car[0])) << endl;
}