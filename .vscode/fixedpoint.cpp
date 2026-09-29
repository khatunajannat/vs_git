// ============================================================
// ============================================================
// Program: Fixed Point Iteration Method - Root Finding
// ============================================================
// ============================================================
#include <iostream>
#include <cmath>
using namespace std;

// Original function f(x) = 0 whose root we want
double f(double x)
{
    return x * x * x - x - 2;
}

// Rearranged convergent form x = g(x), derived from f(x) = 0
double g(double x)
{
    return cbrt(x + 2);
}

int main()
{
    double x0, e;
    int N;

    cout << "Enter initial guess x0: ";
    cin >> x0;

    cout << "Enter tolerable error e: ";
    cin >> e;

    cout << "Enter maximum iterations N: ";
    cin >> N; // safety limit to avoid infinite loop

    double x1;
    int step = 1;

    // Repeatedly apply g(x) until f(x1) is close enough to 0
    do
    {
        x1 = g(x0); // compute next estimate

        // Stop if too many iterations (non-convergent case)
        if (step > N)
        {
            cout << "Not Convergent" << endl;
            return 0;
        }

        cout << "Iteration " << step << ": x1 = " << x1 << ", f(x1) = " << f(x1) << endl;

        x0 = x1; // update guess for next loop
        step++;

    } while (fabs(f(x1)) > e); // stop when close enough to root

    cout << "\nRoot found: " << x1 << endl;

    return 0;
}