#include <iostream>
#include <string>
#include <vector>
#include "../../selam.h"

using namespace std;
 
int main()
{
    selamlama();

    vector<int> v;

    for (int i = 58; i > 48; i--)
    {
        v.push_back(i);
    }

    cout << v.size() <<endl;
    cout << v.capacity() <<endl;
    cout <<endl<< "===================="<<endl;


    if (!v.empty())
    {
        for (int eleman : v)
        {
            cout << eleman<< endl;
        }
        cout <<endl<< "===================="<<endl;
    }
    else
    {
        cout << "eleman yok";
    }

    //v.pop_back();
    v.erase(v.begin()+1);
    v.clear();


    if(!v.empty())
    {
        for (int dongu : v)
        {
            cout << dongu << endl;
        }
    }
        else
    {
        cout << "eleman yok";
    }
    



    



    veda();

    return 0;
}