#include <iostream>
#include <string>
#include "selam.h" 
// YAPAY ZEKA KODU 
using namespace std;

// 1. Alt Struct (İç içe kullanım için)
struct Silah {
    string ad;
    int hasar;
};

// 2. Ana Struct
struct Karakter {
    string isim;
    int can;
    Silah donanim; // İç içe struct kullanımı

    // 3. Constructor (Yapıcı Metot) - Değerleri güvenli atamanın en iyi yolu
    Karakter(string i, int c, Silah s) {
        isim = i;
        can = c;
        donanim = s;
    }

    // 4. Struct içi fonksiyon (Metot)
    void saldir() {
        cout << isim << ", " << donanim.ad << " ile " << donanim.hasar << " hasar vurdu!\n";
    }
};

int main() {
    selamlama();

    // Constructor sayesinde tek satırda ve eksiksiz nesne oluşturma
    Karakter oyuncu("Şövalye", 100, {"Kılıç", 30});

    // Struct içindeki fonksiyonu çağırma
    oyuncu.saldir();
    veda();
    return 0;
}