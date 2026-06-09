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
    ifstream f("hamsi.txt",ios::in);
    ofstream g("guncel_hamsi.txt", ios::app);
    if(!f || !g)
    {
        cout << "Dosya açılamadı";
        return 1;
    }
    string anahtar;
    int deger;
    int toplam;
    while(f >> anahtar >> deger)
    {
        //cout << anahtar << "\t" << deger <<endl;
        deger+=10;
        g<<anahtar<<"\t"<<deger<<endl;
    }
    f.close();
    g.close();
    veda();
    return 0;
}