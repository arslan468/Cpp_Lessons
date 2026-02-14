#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 5, y = 9;
    cout << "\nx:  " << x << "\ny:  " << y;
    cout << "\nToplam: " << x + y << "\n" << "toplamlarının x ile çarpımı: " <<  (x + y) * x;
    ++x;
    --y;
    cout << "\n++x:  " << x << "\n--y:  " << y;
}