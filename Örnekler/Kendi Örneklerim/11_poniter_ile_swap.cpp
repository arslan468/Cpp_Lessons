#include <iostream>
#include <string>
#include "../selam.h" 

using namespace std;


void* pointer_ile_bakiye_swap(int *degisenBakiye, int *degisilenBakiye);


int main ()
{
    selamlama();

    int bakiye1 = 0, bakiye2 = 0;
    int *ptrBakiye1 = &bakiye1;
    int *ptrBakiye2 = &bakiye2;

    cout << endl << "1 Numaralı hesabın bakiyesini giriniz: ";
    cin >> bakiye1;

    cout << endl << "2 Numaralı hesabın bakiyesini giriniz: ";
    cin >> bakiye2;

    cout << endl  << "Swap işlemi öncesi" << endl ;
    cout << endl  << "1 Numaralı Bakiye: " << bakiye1 << endl ;
    cout << endl  << "2 Numaralı Bakiye: " << bakiye2 << endl ;
    

    pointer_ile_bakiye_swap(ptrBakiye1, ptrBakiye2);
    cout << endl  << "Swap işlemi sonrası" << endl ;


    cout << endl  << "1 Numaralı Bakiye: " << bakiye1 << endl ;
    cout << endl  << "2 Numaralı Bakiye: " << bakiye2 << endl ;


    veda();
    return 0;

}   

void* pointer_ile_bakiye_swap(int *degisenBakiye, int *degisilenBakiye)
{
    int tempbakiye = *degisenBakiye;

    *degisenBakiye = *degisilenBakiye;
    *degisilenBakiye = tempbakiye;
}