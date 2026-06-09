#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../../selam.h"

using namespace std;
void notlariDuzenle(vector<int> &notlar)
{
    if(!notlar.empty())
    {
        if(notlar.front()<50)
        {
            notlar.erase(notlar.begin());
        }
        notlar.push_back(100);
    }
    cout <<notlar.size()<<endl;
}

void yazdir(const vector<int> &x)
{
    for(int i:x)
    {
        cout << i <<"\t";
    }
}
 
int main()
{
    selamlama();
    vector <int> v= {1,2,3,4,5,6};
    notlariDuzenle(v);
    yazdir(v);
    veda();
    return 0;
}