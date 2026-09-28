// All possible roots with Newton-Raphson
#include <bits/stdc++.h>
using namespace std;

// Polynomial: x^4 + 4x^3 - 7x^2 - 22x + 24
// Evaluate polynomial using Horner's method
double func(const double a[], double x, int n)
{
    double res = 0;
    for (int i = 0; i <= n; i++)
    {
        res = res * x + a[i];
    }
    return res;
}

// Evaluate derivative using Horner's method
double f_der(const double a[], double x, int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res * x + (n - i) * a[i];
    }
    return res;
}

int main()
{
    double a[10] = {1, 4, -7, -22, 24}; // coefficients, highest degree first
    double x0 = 2.5;                    // initial guess for Newton-Raphson
    double x1;                          // stores the newly computed root estimate
    double error, tolErr = 0.00001;
    int degree = 4;

    cout << fixed << setprecision(10);

    while (degree > 1)
    {
        error = 100;

        while (error > tolErr)
        {
            double fval = func(a, x0, degree);
            double dval = f_der(a, x0, degree);

            x1 = x0 - (fval / dval);
            error = fabs(x1 - x0);
            x0 = x1;
        }

        cout << "\n Root : " << x1 << endl;

        // Synthetic division (deflate the polynomial)
        double b[10] = {0};
        b[0] = a[0];
        for (int i = 1; i <= degree; i++)
        {
            b[i] = b[i - 1] * x1 + a[i];
        }

        degree--; // polynomial is now one degree smaller

        cout << "polynomial coefficient for degree : " << degree << endl;
        for (int i = 0; i <= degree; i++)
        {
            cout << b[i] << endl;
            a[i] = b[i];
        }
        cout << endl;
    }

    // When degree is 1: ax + b = 0, so the root is directly -b/a
    cout << "The root is : " << -a[1] / a[0] << endl;

    return 0;
}