#include <iostream>
#include <string>
#include "../../selam.h"

using namespace std;

class Araba
{
private:
    string marka;
    int hiz;

public:
    Araba(string marka, int hiz)
    {
        this->marka = marka; // "this" ile parametre olan marka, class'ın markasına atanır.
        setHiz(hiz);        
    }

    string getMarka() { return marka; }
    int getHiz() { return hiz; }

    void setHiz(int hiz)
    {
        if (hiz >= 0 && hiz <= 300)
        {
            this->hiz = hiz;
        }
        else
        {
            cout << "Hata: Gecersiz hiz degeri (" << hiz << ")!" << endl;
        }
    }
};

int main()
{
    selamlama();
    Araba oto1("TOGG", 100);
    cout << "Araba: " << oto1.getMarka() << ", Hiz: " << oto1.getHiz() << endl;

    oto1.setHiz(-50);

    oto1.setHiz(150);
    cout << "Yeni Hiz: " << oto1.getHiz() << endl;
    veda();
    return 0;
}