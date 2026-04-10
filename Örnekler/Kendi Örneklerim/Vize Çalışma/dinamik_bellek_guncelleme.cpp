#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;


int* envanterOlustur(int boyut);

void envanteriYazdir(const int* envanter, int boyut);

int* esyaEkle(int* eskiEnvanter, int eskiBoyut, int yeniEsyaGucu);

int main()
{
    int buyukluk = 0;
    cout << "Büyüklük gir: ";
    cin >> buyukluk;
    int* dizi_adres= envanterOlustur(buyukluk);
    envanteriYazdir(dizi_adres, buyukluk);

    int* yeni_adresim = esyaEkle(dizi_adres, buyukluk, 58);
    dizi_adres = nullptr;
    buyukluk++;
    envanteriYazdir(yeni_adresim, buyukluk);

    delete[] yeni_adresim;
    yeni_adresim = nullptr;
    return 0;
}

int* envanterOlustur(int boyut)
{
    int* dizi = new int[boyut]();
    for (int i = 0; i < boyut; i++)
    {
        dizi[i]=((i*4)*2)+6;
    }
    return dizi;

}

void envanteriYazdir(const int* envanter, int boyut)
{
    for (int i = 0; i < boyut; i++)
    {
        cout << (i+1) << ". eleman = " << envanter[i] << endl;
    }
    cout << "================= BİTTİ =============" <<  endl;
}

int* esyaEkle(int* eskiEnvanter, int eskiBoyut, int yeniEsyaGucu)
{
    int* yeni_dizi = new int[eskiBoyut+1];

    for (int i = 0; i < eskiBoyut; i++)
    {
        yeni_dizi[i] = eskiEnvanter[i];
    }
    yeni_dizi[eskiBoyut] = yeniEsyaGucu;

    delete[] eskiEnvanter;
    return yeni_dizi;
}