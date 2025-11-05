#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++) 
    {
        for (int j = 1; j <= 5 - i; j++)
            cout << " ";
        for (int k = 1; k <= 2*i - 1; k++)
            cout << "*";
        cout << "\n";
    }

    cout << endl;

    for(int i = 1; i <= 5; i++)
    {
        for (int j=0; j < i; j++)
            cout << " ";
        for (int k = 5; k > i; k--)
            cout << "*";
        cout << "\n";
    }

    for (int i = 1; i <= 2*5-1; i++) 
    {
        int x = (i <= 5) ? i : 2*5 - i;
        for (int j = 1; j <= x; j++) 
            cout << "*";
        cout << endl;
    }
    
    return 0;
}