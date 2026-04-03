#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

void swap(int &a, int &b)
    {
    int temp = a;
    a = b;
    b = temp;
    }


int main ()
{
    selamlama();

    int x = 58;

    int &y = x;

    int *p = &x;

    cout << endl << "*P = " << *p << endl;
    cout << endl << "P = " << p << endl;

    *p += 5;

    cout << endl << "X = " << x << endl;
    cout << endl << "&Y = " << y << endl;

    y += 5;

    cout << endl << "X = " << x << endl;
    cout << endl << "&Y = " << y << endl;

    int a = 5;
    int b = 10;
    swap(a, b);
    cout <<endl << a << "----" << b;


    veda();
    return(0);
}