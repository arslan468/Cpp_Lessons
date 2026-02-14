#include <iostream>
using namespace std;

int main()
{
    auto x = true;
    cout << "\nDeğer: " << x << "\nTür: " << typeid(x).name();
    auto y = 3241;
    cout << "\nDeğer: " << y << "\nTür: " << typeid(y).name();
    auto z = 32.32;
    cout << "\nDeğer: " << z << "\nTür: " << typeid(z).name();
    
} 