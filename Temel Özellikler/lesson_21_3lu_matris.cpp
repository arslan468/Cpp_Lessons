#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int main ()
{
    selamlama();

    string DiziUcBoyutlu [4][2][2] = {
    {
        { "A", "B" },
        { "C", "D" }
    },

    {
        { "E", "F" },
        { "G", "H" }
    },

    {
        { "I", "İ" },
        { "J", "K" }
    },

    {
        { "L", "M" },
        { "N", "O" }
    }
    };






    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int d = 0; d < 2; d++)
            {
                cout << DiziUcBoyutlu [i][j][d];

            }
            cout << endl;
        }
        cout << endl;
    }
    





    

    veda();
    return(0);
}