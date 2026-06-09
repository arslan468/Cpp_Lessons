#include <iostream>
using namespace std;

class Veritabani {
private:
    string dbIsmi;

public:
    // Constructor (Bağlantıyı kurar / Bellek ayırır)
    Veritabani(string isim) {
        dbIsmi = isim;
        cout << dbIsmi << " baslatildi." << endl;
    }

    // Destructor (Bağlantıyı koparır / Belleği temizler)
    ~Veritabani() {
        cout << dbIsmi << " kapatildi ve temizlendi." << endl;
    }
};

int main() {
    Veritabani db("Lokal_DB"); // Constructor çalışır.
    
    return 0; 
} // Kapsam biter, Destructor otomatik çalışır.