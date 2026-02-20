#include <iostream>
#include <string>
#include "../selam.h" 
using namespace std;

int main ()
{
    selamlama();
    int sayi_dizisi[10] {} , En_Buyuk = 0;
    int boyut = ((sizeof(sayi_dizisi))/sizeof(sayi_dizisi[0]));

    for (int i = 0; i <boyut ; i++)
    {
        cout << "\n" << (i+1) <<". sayıyı giriniz: "; cin >> sayi_dizisi[i];
    }

    for (int j = 0; j < boyut; j++)
    {
        if (sayi_dizisi[j] > En_Buyuk)
        {
            En_Buyuk = sayi_dizisi[j];
        }
        
    }

    cout << "\nGirmiş olduğunuz sayılardan en büyüğü: " << En_Buyuk << endl;
    veda();
    return 0;
}