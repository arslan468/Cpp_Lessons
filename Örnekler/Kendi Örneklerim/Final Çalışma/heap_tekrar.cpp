#include <iostream>
#include <string>
#include "../../selam.h"

using namespace std;

void diziElemanEkleme(int *dizi, int boyut);

void yazdir(int dizi[], int boyut);
 
int main()
{
    selamlama();
    double *p = new double;
    *p = 58.3;
    cout << "değer= "<< *p <<"\nadres= "<< p;
    delete p;
    p = nullptr;

    cout << endl<< "Kaç elemanlı bir dizi oluşturmak istersiniz: ";
    int dizibyt;
    cin >> dizibyt;
    int* dizi= new int[dizibyt];
    diziElemanEkleme(dizi, dizibyt);
    yazdir(dizi, dizibyt);

    delete[] dizi;
    dizi = nullptr;

    

    veda();

    return 0;
}

void diziElemanEkleme(int* dizi, int boyut)
{
    int deger;
    for (int i = 0; i <boyut; i++)
    {

        cout << endl << (i+1) << ". eleman için bir değer giriniz: ";
        cin >> deger;
        dizi[i] = deger; 
    }
}

void yazdir(int dizi[], int boyut)
{
    for(int i=0; i <boyut; i++)
    {
        cout << "Dizinin " << (i+1)<< ". elemanı: " << dizi[i]<< endl;
    }
}
