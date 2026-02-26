#include <iostream>
#include <string>
#include <cctype>
#include "../selam.h" 

using namespace std;

int main ()
{
    selamlama();

    string ad;

    cout << "Tam adinizi girin: ";
    getline(cin, ad);

    int uzunluk = ad.length();
    cout << endl << "Girdinin uzunluğu: " << uzunluk << endl;

    string buyukAd = ad;
    for (int i = 0; i < uzunluk; i++)
    {
        buyukAd[i] = toupper(buyukAd[i]);
    }
    cout << endl  << "Büyükk harf: " << buyukAd << endl;


    
    string kucukAd = ad;
    for (int i = 0; i < uzunluk; i++)
    {
        kucukAd[i] = tolower(kucukAd[i]);
    }
    cout << endl  << "Küçük harf: " << kucukAd << endl;



    int boslukIndeksi = ad.find(' ');
    string ilkAd = "";
    string soyad = "";

    if (boslukIndeksi != string::npos) {
        ilkAd = ad.substr(0, boslukIndeksi);
        soyad = ad.substr(boslukIndeksi + 1);
    } else {
        ilkAd = ad;
    }





    cout << endl  << "Soyadıon tersten yazılışı: ";
    int deger = (soyad.length() - 1);
    for (int i = deger ; i >= 0; i--)
    {
        cout << soyad[i];
    }
    cout << endl;

    cout  << endl  << "Merhaba " << ilkAd << "! Soyadınız " << soyad << " " 
         << soyad.length() << " karakterden oluşuyor." << endl;

    veda();
    return(0);
}