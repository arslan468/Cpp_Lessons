#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int main ()
{
    selamlama();

    string ders_adi = "Programlama-1";

    string &referans_ders = ders_adi;

    cout << "ders-adi değişkeni çıktısı = " << ders_adi << endl << "referans çıktısı = " << referans_ders << endl;

    referans_ders = "Programlama-2";

    cout << "\nders-adi değişkeni çıktısı = " << ders_adi << endl << "referans çıktısı = " << referans_ders << endl;
    

    veda();
    return(0);
}