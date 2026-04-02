#include "selam.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono> // Süre ölçümü için gerekli kütüphane

using namespace std;
using namespace std::chrono;

// ---- YAPAY ZEKA KODU ----

int main()
{

    selamlama();

    cout << "Veri hazirlaniyor (1 Milyon yazi)..." << endl;
    // İçinde 100 karakter olan 1.000.000 adet string oluşturuyoruz
    vector<string> metinler(1000000, string(100, 'A'));

    long long onemsizToplam = 0; // Döngü boş kalmasın diye

    // --- YAVAŞ DÖNGÜ (KOPYALAYARAK) ---
    auto basla1 = high_resolution_clock::now();

    for (string kopya : metinler)
    { // Her elemanı hafızada baştan yaratır
        onemsizToplam += kopya.length();
    }

    auto bitis1 = high_resolution_clock::now();
    auto sure1 = duration_cast<milliseconds>(bitis1 - basla1).count();
    cout << "Yavas (Kopyalama) Sure: " << sure1 << " milisaniye" << endl;

    onemsizToplam = 0;

    // --- HIZLI DÖNGÜ (REFERANS İLE) ---
    auto basla2 = high_resolution_clock::now();

    for (const string &referans : metinler)
    { // Kopyalamaz, orijinaline bakar
        onemsizToplam += referans.length();
    }

    auto bitis2 = high_resolution_clock::now();
    auto sure2 = duration_cast<milliseconds>(bitis2 - basla2).count();
    cout << "Hizli (Referans) Sure : " << sure2 << " milisaniye" << endl;

    veda();
    return 0;
}