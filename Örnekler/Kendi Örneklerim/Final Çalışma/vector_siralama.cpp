#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../../selam.h"

using namespace std;

void selectionSort(vector<int>&v)
{
    int n=v.size();
    for (int i = 0; i < n-1; i++)
    {
        int enKucukIndex=i;
        for(int j=i+1; j<n;j++)
        {
            if(v[j]<v[enKucukIndex])
            {
                enKucukIndex=j;
            }
        }
        if(enKucukIndex!=i)
        {
            int gecici=v[i];
            v[i]=v[enKucukIndex];
            v[enKucukIndex]=gecici;
        }
    }
    
}

void yazdir(vector <int> &v)
{
    for(int x:v)
    {
        cout << x << "\t";
    }
}
 
int main()
{
    selamlama();
    vector <int> v={2,33,22,10};
    selectionSort(v);
    yazdir(v);

    veda();
    return 0;
}