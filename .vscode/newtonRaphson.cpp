#include <bits/stdc++.h>
using namespace std;

// Evaluate polynomial at x using Horner's method
double func(double *a, double x, int n)
{
    double res = 0;
    for (int i = 0; i <= n; i++)
    {
        res = res * x + a[i]; // Horner's nested multiplication
    }
    return res;
}

// Evaluate derivative of polynomial at x using Horner's method
double f_der(double *a, double x, int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res * x + (n - i) * a[i]; // derivative coefficient trick
    }
    return res;
}

int main()
{
    double a[10] = {1, 4, -7, -22, 24}; // polynomial coefficients (highest
degree first) 
    double x0 = 2.5;                       // initial guess for Newton-Raphson
double x1;                                 // next estimate of root
double error, tolErr = 0.00001;            // stopping tolerance
int degree = 4;                            // current polynomial degree

cout << fixed << setprecision(10);

// Loop reduces degree by 1 each time a root is found
while (degree > 1)
{
    error = 100;

    // Newton-Raphson iteration to find one root
    while (error > tolErr)
    {
        double fval = func(a, x0, degree);
        double dval = f_der(a, x0, degree);

        x1 = x0 - (fval / dval); // Newton-Raphson formula
        error = fabs(x1 - x0);   // check convergence
        x0 = x1;
    }

    cout << "\n Root : " << x1 << endl;

    // Synthetic division: divide out (x - x1) from the polynomial
    double b[10] = {0};
    b[0] = a[0];
    for (int i = 1; i <= degree; i++)
    {
        b[i] = b[i - 1] * x1 + a[i];
    }

    degree--; // polynomial is now one degree smaller

    // Copy reduced polynomial coefficients back into a[]
    cout << "polynomial coefficient for degree : " << degree << endl;
    for (int i = 0; i <= degree; i++)
    {
        cout << b[i] << endl;
        a[i] = b[i];
    }
    cout << endl;
}

// Last remaining polynomial is linear: ax + b = 0
cout << "The root is : " << -a[1] / a[0] << endl;

return 0;
}
