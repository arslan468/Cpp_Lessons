#include <iostream>
#include <string>
#include "../selam.h" 

using namespace std;

// mükemmel sayı kendisi hariç tam sayı bölenlerinin toplamına eşit olan sayı
// örnek 6 = 1 + 2 + 3

int main()
{
    selamlama();
    int sayi, toplam = 0;
    cout << "Bir sayı giriniz: ";
    cin >> sayi;

    for (int i = 1; i < sayi; i++)
    {
        if ( sayi % i == 0)
        {
            toplam += i;
        }
    }

    if (sayi == toplam)
    {
        cout  << endl <<"'"<<sayi<< "' mükemmel sayıdır.";
    }

    else
    {
        cout << endl  <<"'"<<sayi<< "' mükemmel sayı değildir.";
    }
    




    veda();
    return 0;
}

