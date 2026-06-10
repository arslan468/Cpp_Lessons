#include <iostream>
using namespace std;

int main() {
    int sayi = 1234, toplam = 0;
    while(sayi > 0) {
        toplam += sayi % 10;
        sayi /= 10;
    }
    cout << "Basamak Toplami: " << toplam << endl;
    return 0;
}