#include <iostream>
#include <string>
#include "../selam.h"

using namespace std;

int degerGetir(const int &anahtar);
int degerGetir(const double &oran);

int main()
{
    selamlama();

    int id = 58;

    double katsayi = 5.8;

    degerGetir(id);
    degerGetir(katsayi);

    veda();
    return 0;
}

int degerGetir(const int &anahtar)
{
    cout << endl
         << "İnt fonksiyon içinde " << anahtar << endl;
    return 0;
}

int degerGetir(const double &oran)
{
    cout << endl
         << "Double fonksiyon içinde " << oran << endl;
    return 0;
}