#include <iostream>
using namespace std;


int& sec(int &a, int &b) {
if (a > b)
return a;
else
return b;
}

int main()
{
int x = 10;
int y = 20;
sec(x, y) = 100;
cout << "x = " << x << endl;
cout << "y = " << y << endl;
return 0;
}