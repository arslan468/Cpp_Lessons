#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

void ornek(double x);
void ornek(int x);


int main ()
{
    selamlama();

    float deger = 3.32;
    int degisken = 3;
    ornek(deger);
    ornek(degisken);

    veda();
    return(0);
}

void ornek(double x)
{
    cout << endl << "Double olan fonksiyonda." << endl;
}
void ornek(int x)
{
    cout << endl << "İnt olan fonksiyonda." << endl;
}