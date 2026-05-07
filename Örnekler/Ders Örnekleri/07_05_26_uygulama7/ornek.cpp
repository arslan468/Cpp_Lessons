#include <iostream>
#include <string>
using namespace std;



class Ogrenci { // Class: Kalıp
public:
    string isim;
    void yazdir() { cout << isim << endl; } // Veri ve fonksiyon bir arada
};

int main() {
    Ogrenci o1; // o1: Nesne (Somut örnek)
    o1.isim = "Ali";
    o1.yazdir();
    return 0;
}