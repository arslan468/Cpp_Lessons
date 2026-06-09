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
    ofstream f("notlar.txt", ios::app);
    if(!f)
    {
        cout << "dosya açılamadı ";
        return 1;
    }

    string girdi;
    int sayac1=0;
    while(true)
    {
        getline(cin,girdi);
        if(girdi =="q")
        {
            break;
        }
        sayac1++;
        f << girdi<<endl;
    }
    f.close();
    cout << sayac1<<endl;
    ifstream f1("notlar.txt");
    if(!f1)
    {
        cout<<"dosya açılamadı";
        return 1;
    }
    string satir;
    int bosluk,sayac=0;
    int not_ ;
    double toplam=0;
    string isim;
    while(getline(f1,satir))
    {
        //cout << satir << endl;
        bosluk = satir.rfind(' ');
        isim = satir.substr(0, bosluk);
        not_ = stoi(satir.substr(bosluk+1));
        sayac++;
        toplam+=not_;
        //cout << isim << endl << " not : "<< not_ << endl;
    }
    f1.close();
    cout << "Ortalama: "<< (toplam/(double)sayac);
    veda();
    return 0;
}