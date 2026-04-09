#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;

int main()
{
    selamlama();

    double x = 5.8;

    int y = x; // risklidir veri kaybı yaşanır
    cout << "x: " << x <<endl;
    cout << "y: " << y <<endl;

    veda();
    return(0);
}