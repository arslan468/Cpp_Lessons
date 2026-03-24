#include <iostream>
#include <string>
#include "../selam.h"

using namespace std;

int main()
{

    selamlama();

    int alinan_deger, sayac = 0;

    cout << "Bir sayı giriniz: ";
    cin >> alinan_deger;

    for (int i = 1; i <= alinan_deger; i++)
    {
        if ((alinan_deger % i) == 0)
        {
            sayac++;
            // cout << endl << "i değeri " << i << endl << "sayaç" << sayac << endl;
        }
    }

    if (sayac == 2)
    {
        cout << endl
             << "Girmiş olduğunuz sayı asal sayıdır." << endl
             << sayac;
    }
    else
    {
        cout << endl
             << "Girdiğiniz sayı asal sayı değil." << endl
             << sayac;
    }

    veda();
    return 0;
}