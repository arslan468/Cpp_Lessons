#include <iostream>
#include <string>
#include <vector>
#include "../../selam.h"

using namespace std;

template <typename T>
double ortalama(const vector <T>& v)
{
    double toplam=0;
    for(const T &x: v)
    {
        toplam+=x;
    }
    return (toplam/v.size());
}

template <typename t1>
int enYuksek(const vector <t1>& v1)
{
    t1 maks=v1.front();
    for (const t1&y:v1)
    {
        if (maks<y)
        {
            maks =y;
        }
        
    }
    return maks;   
}
 
int main()
{
    selamlama();

    vector<int> v;

    int n;
    cout << "Notlarınızı giriniz; (Çıkış yapmak için -1 giriniz.)"<<endl;
    while(cin >> n && n!=-1)
    {
        v.push_back(n);
    }
    if (!v.empty())
    {
        auto ort = ortalama(v);
        int enYuksekDeger = enYuksek(v);
        cout << "Girilen not sayısı: " << v.size()<<endl;
        cout << "Girdiğiniz en yüksek değer: " << enYuksekDeger<<endl;
        cout << "Girdiğiniz sayıların ortalaması: " << ort<<endl;
    }
    else{
        cout << "not girilmedi";
    }
    


    veda();
    return 0;
}