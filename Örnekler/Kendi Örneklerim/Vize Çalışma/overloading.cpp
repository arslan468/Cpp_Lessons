#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;

void yazdirma(double x);
void yazdirma(int x);


int main()
{
    selamlama();
    float zara = 5.8;
    int sivas = 58;
    yazdirma(zara);
    yazdirma(sivas);
    veda();
    return(0);
}

void yazdirma(double x)
{
    cout << "double fonksiyon x: " << x << endl;
}
void yazdirma(int x)
{
    cout << "int fonksiyon x: " << x << endl;
}