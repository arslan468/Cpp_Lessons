#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;


struct ogrenci
{
    int clasi;
    int age;
    string name;
    string surname;
    double average;
};


int main ()
{
    selamlama();

    ogrenci kisi1;

    kisi1.clasi = 1;
    kisi1.age = 19;
    kisi1.name = "Mehmet Alp";
    kisi1.surname = "Arslan";
    kisi1.average = 3.39;

    ogrenci kisi2 = {2,20,"Alp","ARSLAN", 3.54};

    cout << "İsim = " << kisi1.name << endl << "Soyad = " << kisi1.surname << endl << "Yaş = " << kisi1.age << endl << "Sınıf = " << kisi1.clasi << endl << "Ortalam = " << kisi1.average << endl << endl;
    cout << "İsim = " << kisi2.name << endl << "Soyad = " << kisi2.surname << endl << "Yaş = " << kisi2.age << endl << "Sınıf = " << kisi2.clasi << endl << "Ortalam = " << kisi2.average << endl;


    veda();
    return(0);
}