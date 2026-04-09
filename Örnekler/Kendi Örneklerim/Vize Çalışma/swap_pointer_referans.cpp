#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void swap_islemi(int &deger1,int &deger2);

int main()
{
    int x = 3, y=2;
    swap_islemi(x, y);
    return 0;
}

void swap_islemi(int &deger1,int &deger2){
    int tempbakiye = deger1;
    deger1 = deger2;
    deger2 = tempbakiye;
    cout << "x : " << deger1; 
    cout << "\ny : " << deger2 << endl; 
}