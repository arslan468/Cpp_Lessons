#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../../selam.h"

using namespace std;

class Araba
{
    private: 
        string marka;
        int model;
        int hiz;
    public: 
    Araba(string marka, int model)
    {
        this->marka=marka;
        this->model=model;
        hiz=0;
        cout << marka << "\tOluşturuldu"<<endl; 
    }
    ~Araba()
    {
        cout << this->marka << " Kapatıldı ve temizlendi."<<endl;
    }
    void hizlan(int miktar)
    {
        hiz+=miktar;
    }
    int frenYap(int miktar)
    {
        int deger = hiz-miktar;
        if (0<=deger)
        {
            hiz-= miktar;
        }
        else
        {
            cout << "Hız 0 dan küçük olamaz!"<<endl;
            return 1;
        }
        return 0;
    }
    void bilgiGoster()
    {
        cout << "Marka: "<< marka<<endl<<"Model: "<<model<<endl<<"Hız: "<<hiz<<endl;
    }
};

int main()
{
    selamlama();
    Araba a1("TOGG", 2026);
    a1.hizlan(230);
    a1.frenYap(300);
    a1.frenYap(40);
    a1.bilgiGoster();
    veda();
    return 0;
}