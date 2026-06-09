#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../../selam.h"

using namespace std;
void islemYap(vector<int>& v)
{
    v.push_back(100);
    v.erase(v.begin());
    sort(v.begin(), v.end(),greater<int>());

}
 
int main()
{
    selamlama();
    vector <int> v= {10,20,30,40,58};
    islemYap(v);
    for(int &x:v)
    {
        cout << x << "\t";
    }
    veda();
    return 0;
}