#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter x[" << i + 1 << "] and y[" << i + 1 << "]: ";
        cin >> x[i] >> y[i];
    }

    double sumlnX = 0, sumlnX2 = 0, sumlnY = 0, sumlnXY = 0;

    for (int i = 0; i < n; i++)
    {
        sumlnX += log(x[i]);
        sumlnX2 += log(x[i]) * log(x[i]);
        sumlnY += log(y[i]);
        sumlnXY += log(x[i]) * log(y[i]);
    }

    double b = (n * sumlnXY - sumlnX * sumlnY) / (n * sumlnX2 - sumlnX * sumlnX);
    double lna = (sumlnY - b * sumlnX) / n;

    cout << "lna = " << lna << endl;
    cout << "a =" << exp(lna) << endl;
    cout << "b = " << b << endl;

    cout << "Regression Line: y = " << exp(lna) << "*x^" << b << endl;

    return 0;
}
