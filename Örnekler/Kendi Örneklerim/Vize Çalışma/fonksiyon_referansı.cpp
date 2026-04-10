#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;
// İki değişkenden büyük olanın bellekteki referansını döndürür
int& sec(int &a, int &b) {
    if (a > b) {
        return a; 
    } else {
        return b;
    }
}

int main() {
    selamlama();
    int x = 10;
    int y = 50;

    // sec(x, y) fonksiyonu büyük olan 'y' değişkenini döndürür.
    // Eşitliğin sağına 100 yazdığımızda, aslında doğrudan y = 100 yapmış oluruz.
    sec(x, y) = 100; 

    std::cout << "x: " << x << '\n'; // Çıktı: 10
    std::cout << "y: " << y << '\n'; // Çıktı: 100 (50 iken 100 oldu)

    veda();
    return 0;
}

