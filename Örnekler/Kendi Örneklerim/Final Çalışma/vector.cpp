#include <iostream>
#include <string>
#include <vector>
#include "../../selam.h"

using namespace std;
 
int main()
{
    selamlama();

    vector<int> v;
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {7, 8, 9};

    for (int i = 58; i > 50; i--)
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

        for (int eleman : v1)
        {
            cout << eleman<< endl;
        }
        cout <<endl<< "===================="<<endl;

        for (int eleman : v2)
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
    //v.clear();
    
    
    if(!v.empty())
    {
        for (int& dongu : v)
        {
            //cout << dongu << endl;
            dongu*=2;
        }
        cout <<endl<< "===================="<<endl;/*
        v1.insert(v1.end(), v2.begin(), v2.end() );
        for (int eleman : v1)
        {
            cout << eleman<< endl;
        }
        cout <<endl<< "===================="<<endl;*/
        
    }
    else
    {
        cout << "eleman yok";
    }
    
    //v.insert(v.begin()+3,4,3);
    //v.pop_back();
    
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
    
    
    
    
    
    //cout << v.size() << endl;


    veda();

    return 0;
}