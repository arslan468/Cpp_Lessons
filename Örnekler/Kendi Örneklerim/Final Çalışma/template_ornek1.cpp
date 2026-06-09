#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../../selam.h"

using namespace std;
template <typename T>
T diziMin(const T x[], const int y)
{
    T geciciDeger;
    T minDeger=x[0];
    for (int i = 0; i < y; i++)
    {
        geciciDeger=x[i];
        if (geciciDeger < minDeger)
        {
            minDeger = geciciDeger;
        }
    }
    return minDeger;
}
 
int main()
{
    selamlama();
    int boyut=3;
    int dizi[]={1,2,3};
    double dizi1[]={1.1,2.2,3.3};
    char dizi2[]={'a','b','c'};
    cout << "int: "<< diziMin(dizi,boyut)<<endl;
    cout << "double: "<< diziMin(dizi1,boyut)<<endl;
    cout << "char: "<< diziMin(dizi2,boyut)<<endl;

    veda();
    return 0;
}