#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = " Mehmet Alp ";
    string surname = " ARSLAN ";
    string fullName = name + surname;
    cout << fullName << "\n";

    string firstName = "John ";
    string lastName = "Doe";
    string fullNames = firstName.append(surname); // firstName değişkenini değiştirip sonuna surname ekler ve bunu da fullNames değişkenine aktarır
    cout << fullNames << "\n " << firstName;
}