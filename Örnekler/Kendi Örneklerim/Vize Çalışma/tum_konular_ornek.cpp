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
    selamlama();

    int n = 2;
    int *envanter_adres = envanterOlustur(n);

    envanteriYazdir(envanter_adres, n);

    int* new_adres = esyaEkle(envanter_adres, n, 50);
    envanter_adres = nullptr;
    n++;

    envanteriYazdir(new_adres, n);

    delete[] new_adres;
    new_adres = nullptr;

    veda();
    return 0;
}


int* envanterOlustur(int boyut)
{
    int* envanter_dizi = new int[boyut]();  
    for (int i = 0; i < boyut; i++)
    {
        envanter_dizi[i] = ((i*8)*3)+5;
    }
    

    return envanter_dizi;
}

void envanteriYazdir(const int* envanter, int boyut)
{
    for (int i = 0; i < boyut; i++)
    {
        cout << "Envanter değerler = " << *(envanter + i) << endl;
    }

    cout << endl << "0====== BİTTİ ========" << endl;
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
    eskiEnvanter = nullptr;
    return yeni_dizi;
}