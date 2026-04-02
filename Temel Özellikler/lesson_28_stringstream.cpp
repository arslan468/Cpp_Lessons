#include <iostream>
#include <string>
#include <sstream>
#include "selam.h" 

using namespace std;

int main ()
{
    selamlama();

    string birsicim;
    float Fiyat=0;
    int Adedi=0;

    cout << endl << "======= AÇIK BULUNAN KOD ========" << endl;

    cout << "Fiyat giriniz: ";
    // (cin,birsicim);
    cin >> Fiyat;
    //stringstream(birsicim) >> Fiyat;
    cout << "Adedi: ";
    cin >> Adedi;
    //getline (cin,birsicim);
    //stringstream(birsicim) >> Adedi;
    cout << "Tutari: " << Fiyat*Adedi << " TL\n";
    //cin.get();
    //cout << endl; 


    cout << endl << "======= ÖNLEM ALINMIŞ OLAN KOD ========" << endl;
    getline(cin, birsicim);

    cout << "Fiyat giriniz: ";
    getline(cin,birsicim);
    stringstream(birsicim) >> Fiyat;
    cout << "Adedi: ";
    getline (cin,birsicim);
    stringstream(birsicim) >> Adedi;
    cout << "Tutari: " << Fiyat*Adedi << " TL\n" << endl << "Programı bitirmek için bir tuşa basınız. ";
    cin.get();
    cout << endl;    
    veda();
    return(0);
}