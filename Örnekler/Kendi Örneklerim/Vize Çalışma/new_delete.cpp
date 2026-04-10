#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;

int main()
{
    int n = 3;
    int* dizi = new int[n]();

    int eleman[4] = {10,20,30,40};

    for(int &nat:eleman)
    {
        cout << nat << ". eleman = "<< endl;
    }

    for (int i = 0; i < n; i++)
    {
        dizi[i] = (i*5)+2;
        cout << dizi[i] <<  endl;
    }

    delete[] dizi;
    dizi = nullptr;
    return 0;
}