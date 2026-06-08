#include <iostream>
#include <vector>
#include <string>
#include "../../selam.h"

using namespace std;

template <typename T>
void ikiyeKatla(vector<T>& v )
{
    for(int &x:v)
    {
        //cout << x << "\t";
        x*=2;
    }

}
 
int main()
{
    selamlama();

    vector<int> v = {1,2,3,4,5};
    ikiyeKatla(v);
    if(!v.empty())
    {
        for(int deger:v)
        {
            cout << deger << "\t";
        }
    }

    



    veda();

    return 0;
}