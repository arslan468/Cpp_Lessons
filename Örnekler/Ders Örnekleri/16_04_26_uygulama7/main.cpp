#include <iostream>
#include <string>
#include "donusum.h"
#include "analiz.h"

using namespace std;

int main() {
// 7 günlük Celsius sıcaklık verisi
double hafta[] = {18.5, 22.0, 15.3, 25.8, 20.1, 17.6, 23.4};
int n = 7;
// TODO: Haftalık ortalama, en yüksek ve en düşük değeri yazdırın
double geciciDeger=0;
geciciDeger = gunlukOrtalama(hafta, n);
double ort = geciciDeger;
cout << endl << "Haftalık Ortalam: " << geciciDeger<< endl;

geciciDeger = enYuksek(hafta, n);
cout << endl << "En yüksek sıcaklık: " << geciciDeger<< endl;

geciciDeger = enDusuk(hafta, n);
cout << endl << "En düşük sıcaklık: " << geciciDeger<< endl;

// TODO: Ortalama sıcaklığı Fahrenheit ve Kelvin'e çevirip yazdırın

geciciDeger = celsiusToFahrenheit(ort);
cout << endl << "Sıcaklık Fahrenheit cinsinden: " << geciciDeger<< endl;

geciciDeger = fahrenheitToCelsius(geciciDeger);
cout << endl << "Sıcaklık Celsius cinsinden: " << geciciDeger<< endl;

geciciDeger = celsiusToKelvin(ort);
cout << endl << "Sıcaklık Kelvin cinsinden: : " << geciciDeger<< endl;

return 0;
}