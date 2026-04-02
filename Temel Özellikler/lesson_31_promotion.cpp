#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int promotion(int x);

int main ()
{
    selamlama();

    char karakter = 'a';

    cout << karakter << endl;

    cout << "sizeof(karakter): " << sizeof(karakter) << endl;
    // Promotion bellek boyutunu değiştirmez
    int donus = promotion(karakter);
    cout << "sizeof(karakter): " << sizeof(karakter) << endl;

    cout << donus;

    veda();
    return(0);
}

int promotion(int x)
{
    cout << "İnt versiyon: " << x << endl;
    
    return x;

}