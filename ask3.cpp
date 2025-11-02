#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    int D;
    double x1, x2;
    cout << "Give a, b, c:";
    cin >> a >> b >> c;
    if (a==0)
        exit(0);
    
    
    D = b*b - 4*a*c;
    cout << "Δ = " << D << "\n";

    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2.0*a);
        x2 = (-b - sqrt(D)) / (2.0*a);
        cout << "Δ > 0\n";
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } 
    else
    { 
        if (D == 0) {
            x1 = -b / (2.0*a);
            cout << "Δ = 0\n";
            cout << "x1 = x2 = " << x1 << endl;
        } 
        else 
        {
            double real = -b / (2.0*a);
            double imag = sqrt(-D) / (2.0*a);
            cout << "Δ < 0\n";
            if(real==0)
            {
                cout << "x1 = " << imag << "i" << endl;
                cout << "x2 = " << imag << "i" << endl;    
            }
            else
            {
                cout << "x1 = " << real << " + " << imag << "i" << endl;
                cout << "x2 = " << real << " - " << imag << "i" << endl;
            }
        }
    }
    return 0;
}