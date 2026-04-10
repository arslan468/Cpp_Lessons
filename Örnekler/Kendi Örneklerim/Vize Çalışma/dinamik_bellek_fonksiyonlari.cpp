#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;

int* ekle(int *eskiDizi, int &eskiBoyut, int skor);

void yazdirma(const int *dizi, int boyut);
 
int main()
{
    selamlama();

    int x = 3;
    int* dinamik_dizi = new int[x]();

 
    yazdirma(dinamik_dizi, x);



    int* yeni_adresi = ekle(dinamik_dizi, x, 58);
    dinamik_dizi = nullptr;
    x++;
    yazdirma(yeni_adresi, x);

    delete[] yeni_adresi;
    yeni_adresi = nullptr;

    
    veda();
    return 0;
}

void yazdirma(const int *dizi,int boyut)
{
    for (int i = 0; i <boyut; i++)
    {
        cout << (i+1) <<". değer: " << dizi[i]<< endl;
    }

    cout << "============ BİTTİ ==============="<< endl;
}


int* ekle(int *eskiDizi, int &eskiBoyut, int skor)
{
    int* yeni_dizi = new int[eskiBoyut+1]();
    for (int i = 0; i < eskiBoyut; i++)
    {
        yeni_dizi[i] = eskiDizi[eskiBoyut];
    }
    yeni_dizi[eskiBoyut] = skor;
    delete[] eskiDizi;
    return yeni_dizi;
}