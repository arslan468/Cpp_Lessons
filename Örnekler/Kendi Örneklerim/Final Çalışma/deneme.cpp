#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../../selam.h"

using namespace std;
class Okul
{
    private:
    string isim;
    int puan,sinif;
    public:
    Okul(string isim, int sinif)
    {
        this->isim=isim;
        this->sinif=sinif;
        puan=0;
        cout << isim << "\t Oluşturuldu"<<endl;
    }
    ~Okul()
    {
        cout << this->isim<< "\t Kapatıldı ve temizlendi"<<endl;
    }
    void notEkle(int puan)
    {
        this->puan+=puan;
    }
    void bilgiGoster()
    {
        cout << "Ad: " << isim<<endl<<"Sınıf: "<<sinif<<endl<<"Puan: "<<puan<<endl;
    }
};


int main()
{
    selamlama();
    Okul o1("Mehmet", 1);
    Okul o2("Alp", 2);
    o1.notEkle(100);
    o2.notEkle(95);
    o1.bilgiGoster();
    o2.bilgiGoster();
    


    veda();
    return 0;
}