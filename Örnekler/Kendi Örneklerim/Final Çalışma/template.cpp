#include <iostream>
#include <string>
#include <vector>
#include "../../selam.h"

using namespace std;
/*template <typename T> T topla(T x, T x1)
{
    return (x+x1); 
}

template <typename t1, typename t2> t1 carp(t1 x, t2 y)
{
    return (x*y);
}

template <typename K> 
void vektorYazdir(const vector<K>&dizi)
{
    for (K deger: dizi)
    {
        cout << "\t" << deger; 
    }
    cout << endl;<
}

*/



template <typename T>
void vektorYazdir(const T &dizi)
{
    for(T deger:dizi)
    {
        cout << "\t" << deger;
    }
    cout << endl;
}

int main()
{
    selamlama();
    vector<int> sayilar = {1, 2, 3};
    vector<string> harfler = {"A", "B", "C"};
    vektorYazdir(sayilar); // Çıktı: 1 2 3
    vektorYazdir(harfler); // Çıktı: A B C
    veda();
    return 0;
}