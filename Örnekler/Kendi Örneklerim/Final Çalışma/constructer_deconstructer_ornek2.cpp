#include <iostream>
using namespace std;

class Ogrenci {
public:
    string isim;
    double ortalama;

    // Parametreli Constructor
    Ogrenci(string i, double o) { 
        isim = i; 
        ortalama = o; 
    }
};

int main() {
    // Nesne oluşturulurken veriler doğrudan parantez içinde atanır
    Ogrenci o1("Ahmet", 3.5); 
    
    cout << o1.isim << " - " << o1.ortalama << endl;
    
    return 0;
}