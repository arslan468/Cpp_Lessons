#include <iostream>
using namespace std;

// 1. Dinamik 2 Boyutlu Dizi Oluşturma
int** tabloOlustur(int satir, int sutun) {
    // Önce satırları tutacak olan ana pointer dizisini oluştur
    int** tablo = new int*[satir];
    
    // Sonra her bir satır için sütun dizilerini (heap'te) oluştur
    for (int i = 0; i < satir; i++) {
        tablo[i] = new int[sutun];
        
        // Başlangıç değerlerini 0 yapalım
        for(int j = 0; j < sutun; j++) {
            tablo[i][j] = 0;
        }
    }
    return tablo;
}

// 2. Tabloyu Yazdırma
void tabloYazdir(int** tablo, int satir, int sutun) {
    for (int i = 0; i < satir; i++) {
        cout << i + 1 << ". Takim Skorlari: ";
        for (int j = 0; j < sutun; j++) {
            cout << tablo[i][j] << "\t";
        }
        cout << endl;
    }
}

// 3. Tabloya Yeni Satır (Takım) Ekleme
int** takimEkle(int** eskiTablo, int eskiSatir, int sutun, int* yeniSkorlar) {
    // 1 fazla kapasiteli yeni ana pointer dizisi
    int** yeniTablo = new int*[eskiSatir + 1];

    // Eski satırların ADRESLERİNİ yeni tabloya kopyala
    // (Bütün elemanları tek tek kopyalamaya gerek yok, adresleri taşımak yeterli ve çok hızlıdır)
    for (int i = 0; i < eskiSatir; i++) {
        yeniTablo[i] = eskiTablo[i]; 
    }

    // Yeni eklenecek takım için son satıra yer ayır ve değerleri gir
    yeniTablo[eskiSatir] = new int[sutun];
    for (int j = 0; j < sutun; j++) {
        yeniTablo[eskiSatir][j] = yeniSkorlar[j];
    }

    // Sadece eski ANA pointer dizisini sil. 
    // İçindeki satırları silmiyoruz, çünkü onlar artık yeniTablo'ya bağlandı!
    delete[] eskiTablo;

    return yeniTablo;
}

// 4. Belleği Tamamen Temizleme
void tabloSil(int** tablo, int satir) {
    // Önce içerdeki satırları tek tek sil
    for (int i = 0; i < satir; i++) {
        delete[] tablo[i]; 
    }
    // En son ana pointer dizisini sil
    delete[] tablo; 
}

int main() {
    int takimSayisi = 2;
    int kategoriSayisi = 3;

    // 2x3'lük dinamik CTF tablosu
    int** skorTablosu = tabloOlustur(takimSayisi, kategoriSayisi);

    // İlk 2 takımın skorlarını manuel girelim
    skorTablosu[0][0] = 50; skorTablosu[0][1] = 100; skorTablosu[0][2] = 20;
    skorTablosu[1][0] = 80; skorTablosu[1][1] = 40;  skorTablosu[1][2] = 60;

    cout << "--- Baslangic Tablosu ---" << endl;
    tabloYazdir(skorTablosu, takimSayisi, kategoriSayisi);

    // 3. Bir takım yarışmaya katıldı, skorları geldi
    int yeniTakim[3] = {150, 200, 180};
    
    // Tabloyu (satır sayısını) büyüt
    skorTablosu = takimEkle(skorTablosu, takimSayisi, kategoriSayisi, yeniTakim);
    takimSayisi++; // Boyutu güncellemeyi unutma

    cout << "\n--- Yeni Takim Eklendikten Sonra ---" << endl;
    tabloYazdir(skorTablosu, takimSayisi, kategoriSayisi);

    // Kapanışta belleği tamamen iade et
    tabloSil(skorTablosu, takimSayisi);
    skorTablosu = nullptr;

    return 0;
}