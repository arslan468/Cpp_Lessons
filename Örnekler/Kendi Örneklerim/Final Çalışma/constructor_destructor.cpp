#include <iostream>
#include <string>
#include "../../selam.h"


using namespace std;

class Karakter {
private:
    string isim;

public:
    // Constructor (Nesne doğduğunda çalışır)
    Karakter(string i) {
        isim = i;
        cout << isim << " oyuna katildi." << endl;
    }

    // Destructor (Nesne silindiğinde çalışır)
    ~Karakter() {
        cout << isim << " oyundan ayrildi." << endl;
    }
};

int main() {
    cout << "--- Oyun Basliyor ---" << endl;

    // 1. STACK ÜZERİNDE NESNE (Otomatik silinir)
    Karakter oyuncu1("Kahraman"); 

    // 2. HEAP ÜZERİNDE NESNE (Manuel silinmesi zorunludur)
    Karakter* oyuncu2 = new Karakter("Dusman"); 

    cout << "--- Ara Savas ---" << endl;

    // Heap'teki nesneyi biz yok ediyoruz. (Dusman'ın Destructor'ı burada çalışır)
    delete oyuncu2; 
    oyuncu2 = nullptr;

    cout << "--- Oyun Bitiyor ---" << endl;
    return 0; 
    // Program bittiği için Stack'teki nesne otomatik silinir. (Kahraman'ın Destructor'ı burada çalışır)
}