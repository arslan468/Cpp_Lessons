#include <iostream>
#include <string>
#include "selam.h"

using namespace std;

// programın hatası prototip eksik olması
int kare(int x);
int kup(int x);
int mutlak(int x);
int maks(int a, int b);

int main()
{
    selamlama();
    cout << kare(4) << endl;
    cout << kup(3) << endl;
    cout << mutlak(-9) << endl;
    cout << maks(7, 12) << endl;
    veda();
    return 0;
}

int kare(int x) { return x * x; }
int kup(int x) { return x * x * x; }
int mutlak(int x) { return x < 0 ? -x : x; }
int maks(int a, int b) { return a > b ? a : b; }