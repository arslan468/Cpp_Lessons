#include <iostream>
#include <string>
#include <vector>
#include "../../selam.h"

using namespace std;
 
void vectorBirlestir(vector <int>& v, const vector<int>&v1)
{
    for ( int i = 0; i < v1.size(); i++)
    {
        v.push_back(v1[i]);
    }   
}
int main()
{
    selamlama();
    vector<int> v1 = {10, 5, 20};
    vector<int> v2 = {2, 8};
    vectorBirlestir(v1,v2);
    for(int x: v1)
    {
        cout << x << "\t";
    }
    veda();
    return 0;
}