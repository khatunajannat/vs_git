
// ============================================================
// ============================================================
// Program: Bisection Method - Root Finding with Iteration Table
// ============================================================
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// Function whose root we want: f(x) = sqrt(x+1) - x - 0.5
double func(double x)
{
    double sum = sqrt(x + 1) - x - 0.5;
    return sum;
}

int main()
{
    cout << fixed << setprecision(6);

    int iter = 0;
    double x;
    double a, b;
    cin >> a >> b; // read interval [a, b]

    cout << "================================================================================================================" << endl;
    cout << "No|      a|      b|      f(a)|      f(b)|      x0|      f(x0)| sign | Interval | update" << endl;
    cout << "================================================================================================================" << endl;

    // Check if a root exists in [a, b] (sign must differ)
    if (func(a) * func(b) > 0)
    {
        cout << "you wanting me tonight is impossible!!!!!" << endl;
    }
    else
    {
        double curr_root;
        double prev_root = a;
        double err = 100;

        // Repeat bisection until error is small enough
        while (err > 0.00001)
        {
            double tempA = a;
            double tempB = b;
            double interval = abs(tempA - tempB); // current interval width
            iter++;

            string update;
            x = (a + b) / 2; // midpoint estimate
            // For False Position method, replace the line above with:
            // x = (a * func(b) - b * func(a)) / (func(b) - func(a));
            char sign;

            // Track sign of f(x) for display
            if (func(x) > 0)
            {
                sign = '+';
            }
            else
            {
                sign = '-';
            }

            // Decide which half of interval contains the root
            if (func(a) * func(x) < 0)
            {
                b = x;
                update = "upper";
            }
            else if (func(b) * func(x) < 0)
            {
                a = x;
                update = "Lower";
            }
            else
            {
                cout << "Exact root found " << endl;
                update = "exact";
            }

            prev_root = curr_root;
            curr_root = x;
            err = abs(curr_root - prev_root); // convergence check

            printf("\n%2d|  %0.6f|  %0.6f|  %0.6f|  %0.6f|   %0.6f|   %0.6f|   %c|   %0.6f|   %s| \n ", iter, tempA, tempB, func(tempA), func(tempB), x, func(x), sign, interval, update.c_str());
        }

        cout << "Root is: " << x << endl;
    }

    return 0;
}
// ============================================================