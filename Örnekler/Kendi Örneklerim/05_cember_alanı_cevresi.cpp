#include <iostream>
#include <string>
#include "../selam.h" 
using namespace std;

int main()
{
    selamlama();
    double r, pi=3.14;
    cout << "\nDairenin yarıçapını giriniz: ";
    cin >> r;

    cout << "Pİ = 3.14" << endl;

    cout << "Dairenin Alanı: " << (r*r*pi) << endl;

    cout << "Dairenin Çevresi: " << (2*pi*r) << endl;
    veda();
}