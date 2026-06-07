#include <iostream>
#include <string>
#include <fstream>
#include "../../selam.h"

using namespace std;
 
int main()
{
    selamlama();
    ofstream f;
    f.open("data.txt");

    if(f.is_open())
    {
        f << "Deneme\n";
        f<< "2denem";
        f.close();
        cout << "yazma işlemi başarılı";
    }
    else{
        cout << "dosya açılamadı";
    }

    

    veda();

    return 0;
}