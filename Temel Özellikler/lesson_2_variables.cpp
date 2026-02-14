#include <iostream>
using namespace std;

int main()
{
    cout << "int \t= " << sizeof (int) << "byte \tdeğer aralığı  -2147483648 , 2147483647\n" ;
    cout << "char \t= " << sizeof (char) << "byte \tdeğer aralığı  -127, 127  veya 0 , 255\n" ;
    cout << "float \t= " << sizeof (float) << "byte \tdeğer aralığı - , \n" ;
    cout << "double \t= " << sizeof (double) << "byte \tdeğer aralığı - , \n" ;
    cout << "short int = " << sizeof (short int) << "byte \tdeğer aralığı -32,768 , 32,768 \n" ;
    cout << "lon long int = " << sizeof (long long int) << "byte \tdeğer aralığı -(2^63),((2^63)-1) \n" ;
    /*cout << " \t= " << sizeof (int) << "byte \tdeğer aralığı - , \n" ;
    cout << " \t= " << sizeof (int) << "byte \tdeğer aralığı - , \n" ;
    cout << " \t= " << sizeof (int) << "byte \tdeğer aralığı - , \n" ;
    cout << " \t= " << sizeof (int) << "byte \tdeğer aralığı - , \n" ;
    cout << " \t= " << sizeof (int) << "byte \tdeğer aralığı - , \n" ;*/
    cout << "unsigned char = " << sizeof (unsigned char) << "byte değer aralığı  0, 255 \n" ;
    cout << "signed char = " << sizeof (signed char) << "byte   değer aralığı  -127, 127 \n" ;
    return 0;
}