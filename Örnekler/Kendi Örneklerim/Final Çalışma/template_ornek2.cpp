#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../../selam.h"

using namespace std;

template <typename T>
int elemanSay(const T x[], int y, const T aranan)
{
    T index;
    int sayac=0;
    for(int i=0; i < y; i++)
    {
        index = x[i];
        if(index == aranan)
        {
            sayac++;
        }
    }
    return sayac;
}
 
int main()
{
    selamlama();
    int dizi[] = {1,1,1,2,3};
    cout <<     "tekrar sayısı: "<<elemanSay(dizi, 5, 1)<<endl;
    veda();
    return 0;
}