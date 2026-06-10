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
    string satir;

    ofstream f("dosya.txt",ios::app);
    if (!f)
    {
        cout << "Dosya oluşturulmadı\n";
        return 1;
    }
    
    f << "Merhaba Dünya\nBenim Adım Mehmet\nSoyadım Arslan\nİkinci Adım Alp";
    f.close();

    ifstream f1("dosya.txt");
    while (getline(f1,satir))
    {
        cout << satir<<endl;
    }
    f1.close();

    cout << "=======================" <<endl;

    string kelime;
    ifstream f2("dosya.txt");
    while(f2>>kelime)
    {
        cout << kelime<<endl;
    }
    f2.close();

    cout << "=======================" <<endl;


    char c;
    ifstream f3("dosya.txt");
    while(f3.get(c))
    {
        cout << c << endl;
    }
    f3.close();

    veda();
    return 0;
}