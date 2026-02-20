#include <iostream>
#include <string>
using namespace std;

int main()
{
    int Num1;
    int Num2;

    cout << "\nBirinci sayıyı giriniz: ";
    cin >> Num1;
    cout << "\nİkinci sayınızı giriniz: ";
    cin >> Num2;

    cout << "Toplam: " << (Num1+Num2) << endl;
    cout << "Farkı: " << (Num1-Num2) << endl;
    cout << "Çarpım: " << (Num1*Num2) << endl;
    cout << "Bölüm: " << (Num1/Num2) << endl;
    cout << "Mod sonucu: " << (Num1%Num2) << endl;
    double ondaliklibolum = static_cast<double>(Num1) / Num2;
    cout << "Ondalıklı bölüm: " << ondaliklibolum << endl;
    int buyuksayi = (Num1 > Num2) ? Num1 : Num2;
    cout << "Büyük olan sayı: " << buyuksayi << endl;

    bool yanit1 = (Num1 > 0) ? true : false;
    bool yanit2 = (Num2 > 0) ? true : false;

    cout << "Sıfırdan büyük durum kontrol etme\n Birinci Sayı ->  " << yanit1 << "\nİkinci Sayı -> " << yanit2 << endl;
    




    



}