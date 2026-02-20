#include <iostream>
#include <string>
#include "../selam.h" 

using namespace std;

int main()
{
    selamlama();
    int Num1, Num2;
    cout << "\nBirinci sayıyı giriniz: "; cin >> Num1;
    
    cout << "\nİkinci sayıyı giriniz: "; cin >> Num2;

    if (Num1 == Num2)
    {
        cout << "Girmiş olduğunuz sayılar eşit" << endl;
    }
    else if (Num1 > Num2 )
    {
        cout << "Birinci sayı büyüktür ikinci sayıdan" << endl;
    }
    else 
    {
        cout << "İkinci sayı büyüktür birinci sayıdan" << endl;
    }
    veda();
    return 0;
}