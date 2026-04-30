#include <iostream>
using namespace std;

int main() {
    int n = 91;
    bool asalmi = true;
    if (n <= 1) asalmi = false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            asalmi = false;
            break;
        }
    }
    if(asalmi) cout << "Asaldir";
    else cout << "Asal degildir";
    return 0;
}