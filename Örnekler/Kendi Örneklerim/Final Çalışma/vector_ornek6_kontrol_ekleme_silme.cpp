#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../../selam.h"

using namespace std;
void vectorGuncelle(vector<int>& v)
{
    if(!v.empty())
    {
        v.pop_back();
        v.insert(v.begin(), 50);
    }
}

int main()
{
    selamlama();
    vector <int> v={10,20,30,40,58};
    vectorGuncelle(v);
    for(int &x:v)
    {
        cout << x << "\t";
    }
    veda();
    return 0;
}