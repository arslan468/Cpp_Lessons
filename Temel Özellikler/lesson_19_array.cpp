#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int main ()
{
    selamlama();
    string car[5] = {"Audi", "BMW", "TOGG", "TOGG", "Tesla"};
    string cars[5];
    cars[0] = "Volvo";
    cars[1] = "BMW";
    cars[2] = "Ford";
    cars[3] = "Mazda";
    cars[4] = "Tesla";
    for (int i = 0; i < 5; i++) 
    {
        cout << (i+1) << " = " << cars[i] << "\n";

    }
    cout << endl << endl;
    for (int i = 0; i < 5; i++) 
    {
        cout << (i+1)<< " = " << car[i] << "\n";
    }


    cout <<endl << "array length = " << (sizeof(cars) / sizeof(cars[0])) << endl;


    veda ();
    return(0);
}