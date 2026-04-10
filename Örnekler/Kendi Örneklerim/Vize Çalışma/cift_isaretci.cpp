#include <iostream>
#include <string>
#include <cctype>
#include "../../selam.h"

using namespace std;
 
int main()
{
    selamlama();

    int x = 58;
    int * ptr = &x;
    int **dptr = &ptr;

    cout << "x   : " << x <<endl;
    cout << "&x  : " << &x <<endl;
    cout << "ptr : " << ptr <<endl;
    cout << "*ptr : " << *ptr <<endl;
    cout << "&ptr : " << &ptr <<endl;
    cout << "dptr : " << dptr <<endl;
    cout << "&dptr : " << &dptr <<endl;
    cout << "*dptr : " << *dptr <<endl;
    cout << "**dptr: " << **dptr <<endl;

    veda();

    return 0;
}