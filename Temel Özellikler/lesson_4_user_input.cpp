#include <iostream>
#include <string>
using namespace std ;

int main()
{
    int myNum = 19, myNum1 = 23;
    cout << myNum + myNum1;
    cout << "\nBirinci sayınızı giriniz: ";
    cin >> myNum;
    cout << "\nİkinci sayınızı giriniz: ";
    getline(cin, myNum1);
    cout << "\nYeni toplam:\t" << myNum1 + myNum;
}
