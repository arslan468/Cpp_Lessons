#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;

void swap(int &deger, int &deger2);
void* swap(int *deger, int *deger2);

 
int main()
{
    selamlama();

    int x=5, y=8;
    int *xptr= &x;
    int *yptr = &y;
    cout << "x : " << x << endl << "y : " <<y <<endl; 
    swap(x,y);
    cout << "x : " << x << endl << "y : " <<y <<endl; 
    swap(xptr, yptr);
    cout << "x : " << x << endl << "y : " <<y <<endl; 

    veda();
    return 0;
}

void swap(int &deger, int &deger2)
{
    cout << "Referans swap" << endl;
    int temp = deger;
    deger = deger2;
    deger2 = temp;
}

void *swap(int *deger, int *deger2)
{
    cout << "Pointer swap" << endl;
    int temp = *deger;
    *deger = *deger2;
    *deger2 = temp;
}