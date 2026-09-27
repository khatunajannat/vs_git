#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 5;
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {0.5, 2, 4.5, 8, 12.5};

    double sumlnX = 0, sumlnX2 = 0, sumlnY = 0, sumlnXY = 0;

    for (int i = 0; i < n; i++)
    {
        sumlnX += log(x[i]);
        sumlnX2 += log(x[i]) * log(x[i]);
        sumlnY += log(y[i]);
        sumlnXY += log(x[i]) * log(y[i]);
    }

    cout << "Sum(lnX)  = " << sumlnX << endl;
    cout << "Sum(lnY)  = " << sumlnY << endl;
    cout << "Sum(lnXY) = " << sumlnXY << endl;
    cout << "Sum(lnX^2)= " << sumlnX2 << endl;

    double b = (n * sumlnXY - sumlnX * sumlnY) / (n * sumlnX2 - sumlnX * sumlnX);
    double lna = (sumlnY - b * sumlnX) / n;
    double a = exp(lna);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Power Regression Model:" << endl;
    cout << "y = " << a << " * x^" << b << endl;

    double predictX = 5;
    double predictY = a * pow(predictX, b);
    cout << "Predicted units for " << predictX << " hours = " << predictY << endl;

    // SSE = sum of (yi - yi_hat)^2
    double sse = 0;
    for (int i = 0; i < n; i++)
    {
        double yHat = a * pow(x[i], b);
        sse += (y[i] - yHat) * (y[i] - yHat);
    }
    cout << "SSE = " << sse << endl;

    return 0;
}
