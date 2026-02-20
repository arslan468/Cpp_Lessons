#include <iostream>
#include <string>
#include "../selam.h" 

using namespace std;

int main ()
{
    selamlama();
    int Num1, Num2, sonuc = 0;
    cout << "\nÇarpım yapılmasını istediğiniz sayıları sıra ile giriniz: "; cin >> Num1 >> Num2;

    for (int i = 0; i < Num1; i++)
    {
        sonuc += Num2;
    }

    cout << "\t"<< Num1 << " * " << Num2 << " işleminin sonucu:  " << sonuc << endl; 
    veda();
}