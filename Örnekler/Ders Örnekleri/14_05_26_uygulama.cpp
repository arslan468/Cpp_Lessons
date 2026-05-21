#include <iostream>
#include <string>
#include "../selam.h"

using namespace std;

template <typename T>
class SensorDepo
{
private:
    string ad;
    T baslangic;
    T enSonOlcum;
    T enKucukDeger;
    T enBuyukDeger;

public:
    SensorDepo(string ad, T baslangic)
    {
        this->ad = ad;
        this->baslangic = baslangic;
        this->enSonOlcum = baslangic;
        this->enKucukDeger = baslangic;
        this->enBuyukDeger = baslangic;
    }

    void guncelle(T yeniDeger)
    {
        enSonOlcum = yeniDeger;

        if (yeniDeger < enKucukDeger)
        {
            enKucukDeger = yeniDeger;
        }

        if (yeniDeger > enBuyukDeger)
        {
            enBuyukDeger = yeniDeger;
        }
    }

    void raporla()
    {
        cout << ad << " | Son: " << enSonOlcum
             << " | Min: " << enKucukDeger
             << " | Max: " << enBuyukDeger << endl;
    }
};

int main()
{

    selamlama();

    SensorDepo<double> sicaklik("Sicaklik-1", 22.5);
    sicaklik.guncelle(25.3);
    sicaklik.guncelle(1.8);
    sicaklik.guncelle(58.0);
    sicaklik.guncelle(20.8);
    sicaklik.raporla();

    SensorDepo<int> titresim("Titresim-A", 100);
    titresim.guncelle(580);
    titresim.guncelle(20);
    titresim.guncelle(50);
    titresim.raporla();

    SensorDepo<string> durum("Durum-X", "normal");
    durum.guncelle("alarm");
    durum.guncelle("normal");
    durum.raporla();


    string d = "d", a = "a";

    cout << ( 100 < 97) << endl; 
    cout << (d < a) << endl; 
    cout << &a << endl << &d <<endl;
    cout << (&a < &d) << endl; 
    



    veda();

    return 0;
}