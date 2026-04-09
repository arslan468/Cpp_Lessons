#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;

void *pointer_swap(int *degerx, int *degery);

int main()
{

    int x = 5, y = 58;
    int *ptrx = &x;
    int *ptry = &y;

    cout << "x: " << x <<endl;
    cout << "y: " << y <<endl;

    pointer_swap(ptrx, ptry);

    cout << "x: " << x <<endl;
    cout << "y: " << y <<endl;
}

void *pointer_swap(int *degerx, int *degery)
{
    int tempbakiye = *degerx;
    *degerx = *degery;
    *degery = tempbakiye;    
}