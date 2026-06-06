#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// TEMPLATE ÖRNEĞİ: Her tip dizi/vektör için çalışan genel bir yazdırma fonksiyonu
// Referans pass-by-reference kullanarak belleği kopyalamaktan tasarruf ediyoruz.
template <typename T>
void elemanlariYazdir(const vector<T>& liste) {
    for (int i = 0; i < liste.size(); i++) {
        cout << liste[i] << endl;
    }
}

// CLASS ve OOP ÖRNEĞİ
class YazilimOgrencisi {
private:
    string isim;
    int *not_dizisi; // POINTER VE DINAMIK DİZI KULLANIMI
    int ders_sayisi;

public:
    // Constructor (Kurucu)
    YazilimOgrencisi(string isim_param, int dersSayisi_param) {
        // 'this' pointer kullanımı ile isim karmaşasını önlüyoruz
        this->isim = isim_param;
        this->ders_sayisi = dersSayisi_param;
        
        // Heap bellekte dinamik dizi (array) oluşturuyoruz
        this->not_dizisi = new int[ders_sayisi]; 
        for(int i = 0; i < ders_sayisi; i++) {
            not_dizisi[i] = 0; // Varsayılan not ataması
        }
        cout << isim << " icin bellek ayrildi." << endl;
    }

    // Yıkıcı (Destructor) - Memory Leak'i (Bellek sızıntısını) önlemek için hayati önem taşır!
    ~YazilimOgrencisi() {
        delete[] not_dizisi; 
        cout << isim << " silindi, bellek serbest birakildi." << endl;
    }

    // Setter (Veri güvenliği kontrolü ile)
    void notGir(int index, int not_degeri) {
        if (index >= 0 && index < ders_sayisi && not_degeri >= 0 && not_degeri <= 100) {
            not_dizisi[index] = not_degeri;
        } else {
            cout << "Hata: Gecersiz index veya not!" << endl;
        }
    }

    // Getter
    string getIsim() const { return isim; }
    
    // Arkadaş (Yardımcı) fonksiyon. Ostream operatörünü yükleyerek (overloading) 
    // doğrudan cout ile öğrenci nesnesini yazdırabilmemizi sağlıyoruz.
    friend ostream& operator<<(ostream& os, const YazilimOgrencisi& ogr) {
        os << ogr.isim << " -> İlk notu: " << ogr.not_dizisi[0];
        return os;
    }
};

// REFERANS ve DOSYA İŞLEMLERİ (File I/O)
// Vektörü pass-by-reference ile alıyoruz (kopya maliyeti yok).
void dosyayayYaz(const vector<YazilimOgrencisi>& sinifListesi) {
    ofstream dosya("ogrenciler.txt"); // Yazma modu
    
    if (!dosya) {
        cout << "Dosya olusturulamadi!" << endl;
        return;
    }

    for (int i = 0; i < sinifListesi.size(); i++) {
        dosya << sinifListesi[i].getIsim() << endl; 
    }
    
    dosya.close(); // Buffer boşalsın, kilit kalksın diye manuel kapatıyoruz.
    cout << "Ogrenciler basariyla dosyaya yazildi." << endl;
}

int main() {
    // VECTOR ÖRNEĞİ: Sabit boyutlu array yerine dinamik vector kullanıyoruz.
    vector<YazilimOgrencisi> ktuSinifi;

    // Sınıf nesneleri oluşturma (Constructor tetiklenir)
    YazilimOgrencisi ogr1("Ali", 3);
    ogr1.notGir(0, 85);
    
    YazilimOgrencisi ogr2("Ayse", 3);
    ogr2.notGir(0, 95);

    // Vector'e ekleme
    ktuSinifi.push_back(ogr1);
    ktuSinifi.push_back(ogr2);

    // Template fonksiyonunu kullanma (Vector içindeki verileri yazdır)
    cout << "\n--- Sinif Listesi ---" << endl;
    elemanlariYazdir(ktuSinifi); // T tipi otomatik olarak "YazilimOgrencisi" olarak algılandı

    // Dosyaya yazdırma
    cout << "\n--- Dosya Islemi ---" << endl;
    dosyayayYaz(ktuSinifi);

    // main fonksiyonu bittiği an nesneler stack'ten silinir ve YIKICI (Destructor) tetiklenir.
    return 0;
}






