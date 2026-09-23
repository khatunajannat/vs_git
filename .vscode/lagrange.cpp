/*
 * ============================================================
 *  LAGRANGE INTERPOLATION
 * ============================================================
 * Estimates the value of y at an unknown point xp, given a set
 * of known (x, y) data points, by constructing the unique
 * polynomial of degree (n-1) that passes exactly through all n
 * points — without ever explicitly forming that polynomial's
 * coefficients.
 *
 * Formula:
 *      yp = Sum_i [ y[i] * L_i(xp) ]
 * where the Lagrange basis polynomial is:
 *      L_i(xp) = Product_{j != i} [ (xp - x[j]) / (x[i] - x[j]) ]
 *
 * No bugs found in the original implementation — this is a
 * correct, standard implementation. Added: a guard against
 * duplicate x values, which would cause division by zero.
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>
using namespace std;

double lagrangeInterpolation(const vector<double> &x, const vector<double> &y, double xp)
{
    if (x.size() != y.size() || x.empty())
        throw invalid_argument("x and y must be the same non-zero size");

    int n = x.size();

    // Guard against duplicate x values (would cause division by zero below)
    set<double> uniqueX(x.begin(), x.end());
    if (uniqueX.size() != x.size())
        throw runtime_error("x values must be distinct for interpolation");

    double yp = 0;
    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                term *= (xp - x[j]) / (x[i] - x[j]);
        }
        yp += term;
    }
    return yp;
}

int main()
{
    vector<double> x = {1, 2, 3, 4};
    vector<double> y = {2, 4, 6, 8};

    double yp = lagrangeInterpolation(x, y, 2.5);
    cout << "Lagrange Interpolation at x = 2.5: " << yp << "\n";

    return 0;
}
