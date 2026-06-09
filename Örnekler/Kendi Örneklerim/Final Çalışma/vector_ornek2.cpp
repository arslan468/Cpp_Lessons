#include <iostream>
#include <string>
#include <vector>
#include "../../selam.h"

using namespace std;

template <typename T> 
double ort(const vector <T>& v)
{
    double  toplam = 0;
    for(const T&x:v)
    {
        toplam+=x;
    }
    return (toplam/v.size());
}

template <typename t1>
double enDusuk(const vector <t1>& v)
{
    double enDusuk=v.front();
    for(const t1&k:v)
    {
        if(k<enDusuk)
        {
            enDusuk=k;
        }
    }
    return enDusuk;
}

template <typename t2> 
double enYuksek(const vector <t2>&v)
{
    double enYuksek=v.front();
    for(const t2&x:v)
    {
        if(enYuksek<x)
        {
            enYuksek=x;
        }
    }
    return enYuksek;
}

int main()
{
    selamlama();
    vector<double> notlar;
    cout << "Notlarınızı giriniz, Çıkış yapmak için -1 giriniz." <<endl;
    double x=0;
    while(cin>> x && x!=-1)
    {
        notlar.push_back(x);
    }
    cout << "Ortalama:  "<< ort(notlar)<<endl;
    cout << "Endusuk: "<< enDusuk(notlar)<<endl;
    cout << "En Yüksek: " << enYuksek(notlar)<<endl;
    veda();
    return 0;
}