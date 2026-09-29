
// ============================================================
// ============================================================
// Program: Newton-Raphson Method - Root Finding (Basic)
// ============================================================
// ============================================================
#include <bits/stdc++.h>

using namespace std;

// Function whose root we want to find: f(x) = x^3 - x - 2
double f(double x)
{
    return x * x * x - x - 2;
}

// Derivative of f(x), needed for Newton-Raphson formula
double f_der(double x)
{
    return 3 * x * x - 1;
}

int main()
{
    double x0, e;

    cout << "Enter initial guess x0: ";
    cin >> x0;

    cout << "Enter tolerable error e: ";
    cin >> e;

    double x1, f1;
    int step = 0;

    // Repeat until f(x1) is small enough
    do
    {
        // Avoid division by zero if derivative vanishes
        if (f_der(x0) == 0.0)
        {
            cout << "Mathematical error: derivative is zero." << endl;
            return 0;
        }

        // Core Newton-Raphson formula: move closer to root
        x1 = x0 - f(x0) / f_der(x0);

        x0 = x1; // update for next iteration

        f1 = f(x1); // check how close we are to zero

        step++;
        cout << "Iteration " << step << ": x = " << x1 << ", f(x) = " << f1 << endl;

    } while (fabs(f1) > e); // stop when error is small enough

    cout << "\nRoot found: " << x1 << endl;
    cout << "Number of iterations: " << step << endl;

    return 0;
}