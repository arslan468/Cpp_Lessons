#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    auto x = 3, y = 3;

    
    cout << "Sayı giriniz: ";
    cin >> x;
    cout << "Sayı giriniz: ";
    cin >> y;
    if(x>y)
    {
        cout << "x büyük y'den\n";
    }
    else if(x<y)
    {
        cout << "y büyük x'ten\n";
    }
    else
    {
        cout << "x ve y eşit\n";
    }
}