#include <iostream>
#include <fstream>
#include <string>
#include "fonksiyonlar.h"

using namespace std;

void stokuListele(const string& dosyaAdi)
{
    ifstream ikra;
    ikra.open(dosyaAdi, ios::in);
    if (!ikra)
    {
        cout << "Dosya açılamadı!" << endl;
        return;
    }
    string isim;
    double fiyat=0;
    int stok=0;

    while (ikra >> isim >> fiyat >> stok)
    {
        cout << isim << ": " << fiyat << "TL    Stok Adedi: " << stok <<  endl;

    }
    ikra.close();
}

void urunEkle(const string& dosyaAdi, const string& urun, double fiyat, int adet)
{
    ofstream f;

    f.open(dosyaAdi, ios::app);
    if (!f)
    {
        cout << "Dosya açılamadı!" << endl;
        return;
    }

    f << urun << " " << fiyat << " " << adet << endl; 
    f.close();
}

void urunSil(const string& dosyaAdi, const string& hedef)
{

    
}

void fiyatGuncelle(const string& dosyaAdi, const string& hedef, double yeniFiyat)
{
    
}