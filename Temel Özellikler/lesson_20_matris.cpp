#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int main ()
{

    selamlama(); 

    string iki_boyutlu_dizi [2] [2] = 
    {
        {
            "BİR_BİR", "BİR_İKİ"
        },
        {
            "İKİ_BİR", "İKİ_İKİ"
        }
    };


    string sonradan_tanimlanan_dizi [2] [3];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sonradan_tanimlanan_dizi [i] [j] = "?";
        }
    }
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sonradan_tanimlanan_dizi [i] [j];
        }
        cout << endl;
    }

    veda();
    return(0);
}