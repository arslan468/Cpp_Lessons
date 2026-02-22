#include <iostream>
#include <string>
#include "selam.h" 

using namespace std;

int main ()
{
    selamlama();

    string gun = "Pazar";

    string *ptr = &gun;

    cout << gun << endl << &gun << endl << ptr << endl << *ptr << endl;




    

    veda();
    return(0);
}