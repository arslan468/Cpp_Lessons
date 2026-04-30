#include <iostream>
#include <string>

int main() {
    double derece;
    std::cout << "Derece girin: ";
    if (!(std::cin >> derece)) return 1;

    double pi = 3.14159265358979323846;
    double x = derece * (pi / 180.0);

    double sonuc = 0; 
    double terim = x; 

    for (int n = 1; n <= 100; ++n) {
        sonuc += terim;
        terim *= -1.0 * x * x / ((2 * n) * (2 * n + 1));
        if (terim == 0) break;
    }

    std::cout << "sin(" << derece << ") = " << sonuc << std::endl;

    return 0;
}