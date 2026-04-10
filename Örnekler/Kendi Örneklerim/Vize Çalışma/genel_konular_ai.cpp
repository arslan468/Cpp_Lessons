#include <iostream>
using namespace std;

// --- HAFTA 6: Overloading ve const ---
// Tek bir skoru yazdırmak için (const referans - kopya oluşmaz, değiştirilemez)
void yazdir(const int& deger) {
    cout << "Guncel Skor: " << deger << endl;
}

// --- HAFTA 7: Dizilerin Fonksiyona Geçmesi (Array Decay) ---
// --- HAFTA 6: const Pointer ---
// Dizi elemanları const sayesinde fonksiyon içinde değiştirilemez
void yazdir(const int* dizi, int boyut) {
    cout << "Tum Skorlar: ";
    for (int i = 0; i < boyut; i++) {
        cout << dizi[i] << " ";
    }
    cout << endl;
}

// --- HAFTA 5: Pass by Reference ---
// Referans (&) kullanarak orijinal değişkeni kalıcı olarak değiştirme
void bonusEkle(int& skor, int bonus) {
    skor += bonus; // Kopya değil, bellekteki asıl değer değişir
}

// --- HAFTA 8: Dinamik Dizi ve Widening Array (Bellek Yönetimi) ---
// Mevcut dinamik diziyi büyütüp yeni skor ekleyen fonksiyon
int* ctfSkorEkle(int* eskiDizi, int eskiBoyut, int yeniSkor) {
    // 1. Yeni ve daha büyük bir alan ayır (Heap üzerinde)
    int* yeniDizi = new int[eskiBoyut + 1];

    // 2. Eski elemanları yeni diziye kopyala
    for (int i = 0; i < eskiBoyut; i++) {
        yeniDizi[i] = eskiDizi[i];
    }

    // 3. Yeni elemanı son indekse ekle
    yeniDizi[eskiBoyut] = yeniSkor;

    // 4. Bellek sızıntısını (Memory Leak) önlemek için eski diziyi sil
    delete[] eskiDizi;

    // 5. Yeni dizinin başlangıç adresini döndür
    return yeniDizi;
}

// --- HAFTA 7: Çok Boyutlu Diziler (2D Arrays) ---
// 2 boyutlu dizilerde sütun sayısını (burada 3) belirtmek zorunludur!
void turnuvaOzet(const int matris[][3], int takimSayisi) {
    cout << "\n--- CTF Turnuva Ozeti ---" << endl;
    for (int i = 0; i < takimSayisi; i++) {
        int toplam = 0;
        for (int j = 0; j < 3; j++) {
            toplam += matris[i][j];
        }
        cout << i + 1 << ". Takim Toplam Skoru: " << toplam << endl;
    }
}

int main() {
    // 1. Referans ve Overloading Testi
    int anaSkor = 150;
    yazdir(anaSkor);             // Overload 1 çalışır
    bonusEkle(anaSkor, 50);      // Değer referans ile 200 oldu
    yazdir(anaSkor);             

    cout << "-----------------------" << endl;

    // 2. Dinamik Dizi (Heap) Testi
    int boyut = 3;
    int* skorlar = new int[boyut]; // Çalışma zamanında boyut belirlendi
    skorlar[0] = 100;
    skorlar[1] = 250;
    skorlar[2] = 300;

    cout << "Ekleme Oncesi ";
    yazdir(skorlar, boyut);        // Overload 2 çalışır (Array Decay)

    // 3. Dinamik Diziye Eleman Ekleme
    skorlar = ctfSkorEkle(skorlar, boyut, 450);
    boyut++; // Boyutu manuel artırmamız gerekiyor

    cout << "Ekleme Sonrasi ";
    yazdir(skorlar, boyut);

    // 4. Dinamik Belleği Temizleme (Hayati Önem Taşır)
    delete[] skorlar;   // Heap'teki belleği işletim sistemine iade et
    skorlar = nullptr;  // Dangling pointer (sarkan işaretçi) olmasını engelle

    // 5. Çok Boyutlu Dizi Testi (Stack)
    int takimSkorlari[2][3] = {
        {10, 20, 30}, // 1. Takımın 3 bayrak (flag) skoru
        {50, 40, 60}  // 2. Takımın 3 bayrak skoru
    };
    
    turnuvaOzet(takimSkorlari, 2);

    return 0;
}