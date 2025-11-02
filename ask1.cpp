#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Give one number in [100,998]: ";
    cin >> number;
    cout << (number/100)*1 + ((number/10)%10)*10 + number%10*100 << endl;
    return 0;
}
