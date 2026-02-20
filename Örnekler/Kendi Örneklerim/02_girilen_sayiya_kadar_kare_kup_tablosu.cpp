#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int GirilenSayi;
    double kare, kup;

    cout << "\n\nPozitif bir sayı giriniz girmiş olduğunuz sayıya kadar olan sayıların karesini ve küpü tablo halinde oluşturulcak.\n\t->";
    cin >> GirilenSayi;

    cout << "\tKare---------Küp\t\t"<< endl;

    for (int i = 1; i <= GirilenSayi; i++)
    {
        cout << i << "\t" << (i*i) << "\t\t" << (i*i*i) << endl;
    }
}