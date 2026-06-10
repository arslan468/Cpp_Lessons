#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../../selam.h"

using namespace std;


int main()
{
    selamlama();
    fstream f("hamsi.txt",ios::in);
    ofstream f1("guncel_hamsi.txt", ios::app);
    if(!f || !f1)
    {
        cout << "Dosya açılamadı";
        return 1;
    }
    string anahtar;
    int deger;
    while (f>> anahtar >> deger)
    {
        deger+=10;
        f1<<anahtar <<"\t"<<deger<<endl;
    }
    f.close();
    f1.close();
    veda();
    return 0;
}