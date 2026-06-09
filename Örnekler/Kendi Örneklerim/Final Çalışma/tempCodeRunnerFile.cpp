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
    cout << "Ortalama:  "<< ort(notlar);
    veda();
    return 0;
}