#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string metin = "Mehmet Alp Arslan";
    cout << metin << "\nLength: " << metin.length() << "\nSize: " << metin.size(); // length ve size karakter sayısını döndürür length sadece string için kullanılırken size ise başka yapılarda da kullanılır 
    cout << "\n" << metin[0];
    cout << "\n" << metin.at(1);
    cout << "\n" << metin.at(metin.size() - 1);

}