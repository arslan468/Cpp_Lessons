#include <iostream>
#include "../selam.h"
#include <string>
#include <cctype>
using namespace std;

const int ODA = 4;
const int KAT = 5;
const int SAAT = 8; // basitleştirilmiş: 8 saatlik ölçüm

// TODO: 6 fonksiyonun prototiplerini buraya yazın
double ortalama(const double veri[], int n);
double ortalama(const int veri[], int n);

int anormalSayisi(const double sicaklik[], int n, double altSinir, double ustSinir);
void uyariYazdir(const double sicaklik[], int n, double alt, double ust);
void katRaporu(const double sicakliklar[][4], int katSayisi);
int maksIndeks(const double veri[], int n);

int main()
{

    selamlama();

    double sicaklik[] = {21.5, 22.0, 25.5, 29.3, 30.1, 27.8, 23.0, 21.0};

    double katOda[KAT][ODA] = {
        {22.1, 23.4, 21.8, 24.0},
        {20.5, 19.8, 21.2, 20.9},
        {25.6, 26.2, 24.8, 25.1},
        {18.2, 17.9, 18.5, 19.0},
        {23.0, 22.8, 23.5, 22.6}};

    double co2[] = {412.5, 680.3, 1250.8, 520.1, 890.4};
    double buHafta[] = {120.5, 118.3, 125.7, 122.1, 119.8, 131.2, 128.6};
    double gecenHafta[] = {115.2, 117.0, 119.8, 121.5, 118.4, 125.3, 124.1};
    // TODO: Fonksiyon çağrılarını yazın
    // 1) Sıcaklık ortalamasını yazdırın
    double sicaklikOrt = ortalama(sicaklik, SAAT);
    cout << endl
         << " Ortam Sıcaklık ortalaması: " << sicaklikOrt << " ºC" << endl;


    // 2) Anormal ölçüm sayısını yazdırın (sinir: 18-28 C)
    int anormalAdet = anormalSayisi(sicaklik, SAAT, 18.0, 28.0);
    cout << endl <<"=======================";

    cout << endl << "Anormal olan ölçümler " << anormalAdet << " adet" << endl;


    // 3) Anormal ölçümleri uyariYazdir ile listeleyin
    uyariYazdir(sicaklik, SAAT, 18.0, 28.0);


    // 4) Kat bazlı sıcaklık raporunu yazdırın
    katRaporu(katOda, KAT);


    // 5) En yüksek CO2 odasını bulun ve gerekirse uyarı verin
    int maksCO2Indeks = maksIndeks(co2, KAT);
    cout << endl <<"=======================" << endl;

    cout << endl
         << "En yüksek CO2 ölçümü: " << co2[maksCO2Indeks] << " ppm ( ❗️" << (maksCO2Indeks + 1) << " numaralı oda)" << endl;
    if (co2[maksCO2Indeks] > 1000.0)
    {
        cout << endl
             << "🚨Uyarı‼️ : Oda " << (maksCO2Indeks + 1) << " CO2 seviyesi yüksek!" << endl;
    // 6) Bu hafta ve geçen hafta enerji ortalamalarını
        double buHaftaOrt = ortalama(buHafta, 7);
        double gecenHaftaOrt = ortalama(gecenHafta, 7);

        cout << endl
             << "Bu haftanın enerji ortalaması: " << buHaftaOrt << " kWh" << endl;

        cout << endl
             << "Geçen haftanın enerji ortalaması: " << gecenHaftaOrt << " kWh" << endl;

        double yuzdeDegisim = ((buHaftaOrt - gecenHaftaOrt) / gecenHaftaOrt) * 100.0;
        cout << endl
             << "Enerji tüketiminde ki bir haftalık değişim: " << yuzdeDegisim << " %" << endl;
    }
    
    veda();
    return 0;
}
// TODO: 6 fonksiyonun gövdelerini buraya yazın

double ortalama(const double veri[], int n)
{
    double toplam = 0.0;
    for (int i = 0; i < n; i++)
    {
        toplam += veri[i];
    }
    return toplam / n;
}

double ortalama(const int veri[], int n)
{
    double toplam = 0.0;
    for (int i = 0; i < n; i++)
    {
        toplam += veri[i];
    }
    return toplam / n;
}

int anormalSayisi(const double sicaklik[], int n, double altSinir, double ustSinir)
{
    int sayac = 0;
    for (int i = 0; i < n; i++)
    {
        if (sicaklik[i] < altSinir || sicaklik[i] > ustSinir)
        {
            sayac++;
        }
    }
    return sayac;
}

void uyariYazdir(const double sicaklik[], int n, double alt, double ust)
{
    int sayac = 1;
    
    for (int i = 0; i < n; i++)
    {
        if (sicaklik[i] < alt || sicaklik[i] > ust)
        {
            cout << endl<< sayac << ". ölçüm : " << sicaklik[i] << " ºC";
            sayac += 1;
        }
        
    }

    cout << endl <<"=======================" << endl;
}

void katRaporu(const double sicakliklar[][4], int katSayisi)
{
    for (int i = 0; i < katSayisi; i++)
    {
        double katOrt = ortalama(sicakliklar[i], ODA);
        cout << endl << (i + 1) << ". katın ortalama sıcaklığı ☀️ : " << katOrt << " ºC" << endl;
    }
}

int maksIndeks(const double veri[], int n)
{
    int maksIndeks = 0;
    for (int i = 1; i < n; i++)
    {
        if (veri[i] > veri[maksIndeks])
        {
            maksIndeks = i;
        }
    }
    return maksIndeks;
}