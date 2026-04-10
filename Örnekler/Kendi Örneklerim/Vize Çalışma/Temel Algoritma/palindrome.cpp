#include <iostream>
using namespace std;

int main() {
    int n = 1234, ters = 0;
    while(n != 0) {
        ters = ters * 10 + (n % 10);
        n /= 10;
    }
    cout << "Ters Hali: " << ters;
    return 0;
}