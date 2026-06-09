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
    ifstream f("hamsi.txt", ios::in);
    ofstream g("guncel_hamsi.txt", ios::app);
    if(!f || !g)
    {
        cout << "dosya açılamadı";
        return 1;
    }
    string satir,anahtar;
    int deger,bosluk;
    while (getline(f,satir))
    {
        bosluk = satir.rfind(' ');
        anahtar = satir.substr(0,bosluk);
        deger = stoi(satir.substr(bosluk+1));
        deger+=10;
        g << anahtar <<"\t" <<deger<<endl;
    }

    f.close();
    g.close();
    veda();
    return 0;
}