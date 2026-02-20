#include <iostream>
#include <string>
using namespace std;
//78987
int main()
{
    int sayi, bir, on, yuz, bin, onbin;
    cout << "\n5 basamaklı bir sayı giriniz: ";
    cin >> sayi;

    bir = sayi % 10;
    sayi = sayi / 10;
    on = sayi % 10;
    sayi = sayi / 10;
    yuz = sayi % 10;
    sayi = sayi / 10;
    bin = sayi % 10;
    sayi = sayi / 10;
    onbin = sayi % 10;

    if (bir == onbin && (onbin+1) == bin && (bir+1) == on)
    {
        if (on == bin && (bin+1) == yuz && (on+1) == yuz)
        {
            cout << endl << "Girmiş olduğunuz sayı palindrom sayıdır." << endl;
            return 0;
        }
        else
        {
            cout << endl << "Girmiş olduğunuz sayı palindrom sayı değildir." << endl;
            return 0;
        }
    }

    cout << endl << "Girmiş olduğunuz sayı palindrom sayı değildir." << endl;
    return 0;




}