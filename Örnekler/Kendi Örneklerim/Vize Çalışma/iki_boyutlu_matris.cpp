#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;
 
int kosegentopla(int dizi[][3],int satir ,int sutun)
{
    int toplam = 0;
    for (int i = 0; i < satir; i++)
    {
        for(int j=0; j < sutun; j++)
        {
            if (i==j)
            {
                toplam = toplam + dizi[i][j];
            }
            
        }
    }
    return toplam;
}
int main()
{
    int dizi[3][3] = {
        {10,20,30},
        {10,20,30},
        {10,20,30}
    };

    int deger = kosegentopla(dizi, 3, 3);
    cout << deger << endl;
    return 0;
}