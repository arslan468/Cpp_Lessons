#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;
 
void hesapla(const int &kisa, const int &uzun, int* alanPtr, int& cevreRef)
{
    *alanPtr = (kisa * uzun);
    cevreRef = 2*(uzun + kisa);
}

int main()
{
    selamlama();
    int kisa = 10, uzun = 20, alan = 0, cevre = 0;
    hesapla(kisa, uzun, &alan, cevre);
    cout << "Alan: " << alan << endl << "Çevre: " << cevre << endl;

    veda();
    return 0;
}