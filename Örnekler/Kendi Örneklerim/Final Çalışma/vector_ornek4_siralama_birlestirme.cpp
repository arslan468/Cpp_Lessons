#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../../selam.h"

using namespace std;
template <typename T>
vector<T> vectorBirlestir(const vector<T>&v,const vector <T>&v1)
{
    vector <T> birlesim;
    for(const T &x:v)
    {
        birlesim.push_back(x);
    }
    for(size_t i=0; i<v1.size(); i++)
    {
        birlesim.push_back(v1[i]);
    }
    sort(birlesim.begin(),birlesim.end());

    return birlesim;
}
 
int main()
{
    selamlama();
    vector<int> v1 = {10, 5, 20};
    vector<int> v2 = {2, 8};
    vector<int> sonuc=vectorBirlestir(v1,v2);
    for(int &x:sonuc)
    {
        cout << x << "\t";
    }

    veda();
    return 0;
}