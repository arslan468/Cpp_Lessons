#include <iostream>
using namespace std;

int main() {
    cout << "dğer gir: ";
    int n;
    cin >> n;
    for (int i = 1; i <=n; i++)
    {

        for (int j = 1; j <=i; j++)
        {
            cout << "*";

        }
        
        for (int j =i+1; j <=n; j++)
        {
            cout <<" ";
        }
        cout <<"\t";
        for(int k=0;k<=n;k++)
        {
            if (i==1|| i ==n || k==0|| k==n )
            {
                cout <<"*";
            }
            else
            {
                cout << " ";
            }

        }
        cout <<endl;
        
    }
    
    


    return 0;
}