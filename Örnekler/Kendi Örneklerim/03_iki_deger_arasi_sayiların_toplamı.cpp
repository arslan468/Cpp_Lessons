#include <iostream>
#include <string>
#include "../selam.h" 

using namespace std;

int main ()
{
    selamlama();
    int Num1, Num2, toplam = 0;
    
    cout << "Girilen iki sayı arasında ki sayıları toplar" << endl << "Girmiş olduğunuz sayılar toplama dahil değildir." << endl;
    cout << "\nBirinci sayıyı giriniz: "; cin >> Num1;
    
    cout << "\nİkinci sayıyı giriniz: "; cin >> Num2;

    if (Num1 < Num2)
    {
        for (int i = Num1; i < Num2 ; i++)
        {
            toplam += i;
        }
    }
    else if(Num1 > Num2)
    {
        for (int i = Num1; i < Num1 ; i++)
        {
            toplam += i;
        }
    }

    cout << "Toplamları: " << toplam << endl;
    
    veda();

}