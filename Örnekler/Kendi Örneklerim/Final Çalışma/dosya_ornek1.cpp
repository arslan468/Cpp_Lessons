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
    ofstream f("hamsi.txt", ios::app);
    if(!f)
    {
        cout << "Dosya açılmadı";
        return 1;
    }

    string satir;
    cout << "Çıkış yapmak için q basınız"<<endl;
    while (true)
    {
        getline(cin,satir);
        if(satir=="q")
        {
            break;

        }
        f << satir<<endl;
    }
    f.close();
    veda();
    return 0;
}