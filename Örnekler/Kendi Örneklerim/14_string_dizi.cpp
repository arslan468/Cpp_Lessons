#include <iostream>
#include <string>
#include "../selam.h"

using namespace std;

int main ()
{
    selamlama();

    string isimler[5] = {"Nur", "Mehmet", "Alp", "Arslan", "Eda"};

    for (int i=0; i<5; i++)
    {
        cout << isimler[i] << endl;
    }
    
    veda();
    return(0);
}