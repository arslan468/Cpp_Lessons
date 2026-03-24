#include <iostream>
#include <string>
#include "../selam.h"

using namespace std;

void degistir(int *a, int *b);

void degistir(int &a, int &b);

int main()
{
    selamlama();

    int birincil = 5, ikincil = 10;
    int *ptra = &birincil;
    int *ptrb = &ikincil;
    const int pi = 3;

    cout << endl
         << "1 Numaralı Değer: " << birincil << endl;
    cout << endl
         << "2 Numaralı Değer: " << ikincil << endl;

    degistir(ptra, ptrb);
    cout << endl
         << "1 Numaralı Değer: " << birincil << endl;
    cout << endl
         << "2 Numaralı Değer: " << ikincil << endl;

    degistir(&birincil, &ikincil);
    cout << endl
         << "1 Numaralı Değer: " << birincil << endl;
    cout << endl
         << "2 Numaralı Değer: " << ikincil << endl;

    veda();
    return 0;
}

void degistir(int *a, int *b)
{

    cout << endl
         << "Şuan pointer değişken fonksiyonu çalışıyor" << endl;
    int tempdeger = *a;

    *a = *b;
    *b = tempdeger;
}

void degistir(int &a, int &b)
{
    cout << endl
         << "Şuan referans değişken fonksiyonu çalışıyor" << endl;

    int tempdeger = a;
    a = b;
    b = tempdeger;
}

void oku(const int *p)// hata verir 
{
    cout << endl
         << "Şuan referans oku fonksiyonu çalışıyor" << endl;
    cout << endl
         << *p << endl;
    *p = 5;
    cout << endl
         << *p << endl;
}
