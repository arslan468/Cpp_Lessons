#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;


void promotion_guvenli_yol(int x);

int main()
{
    selamlama();

    char metin = 'a';

    cout << "metin: " << metin << endl;
    promotion_guvenli_yol(metin); // otomatik olarak int e yükseltildi veri kaybı yaşanmaz

    veda();
    return(0);
}

void promotion_guvenli_yol(int x)
{
    cout << "metin: " << x << endl;
}
