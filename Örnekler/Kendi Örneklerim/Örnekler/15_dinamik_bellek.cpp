#include <iostream>
#include <string>
#include "../selam.h"

using namespace std;

int* elemanEkle(int* eskiDizi, int eskiBoyut, int yeniEleman);

int* dizi_olustur(int n);

int main ()
{
    int buyuklugu=0;
    cout << "Kaç elemanlı dizi olsun: ";
    cin >> buyuklugu;

    int* dizi = dizi_olustur(buyuklugu);


}

int* dizi_olustur(int n)
{
    int* liste = new int[n];
    return liste;
}

int* elemanEkle(int* eskiDizi, int eskiBoyut, int yeniEleman)
{
    int *yenidizi = new int[eskiBoyut + 1];
    for (int i = 0; i < eskiBoyut; i++)
    {
        yenidizi[i] = eskiDizi[i];
    }
    yenidizi[eskiBoyut] = yeniEleman;
    delete[] eskiDizi;
    return yenidizi;
}