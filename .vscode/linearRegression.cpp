/*
 * ============================================================
 *  LINEAR REGRESSION (Least Squares Method)
 * ============================================================
 * Fits a straight line  y = a + b*x  through a set of (x, y)
 * data points by minimizing the sum of squared vertical errors.
 *
 * Formulas (derived from setting partial derivatives of the
 * squared-error sum to zero, i.e. the "normal equations"):
 *
 *      b = (n*Sum(xy) - Sum(x)*Sum(y)) / (n*Sum(x^2) - Sum(x)^2)
 *      a = (Sum(y) - b*Sum(x)) / n
 *
 * Fix applied: guard against division by zero, which happens
 * when all x values are identical (zero variance in x) — in
 * that case a line of best fit is undefined.
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

pair<double, double> linearRegression(const vector<double> &x, const vector<double> &y)
{
    if (x.size() != y.size() || x.empty())
        throw invalid_argument("x and y must be the same non-zero size");

    int n = x.size();
    double sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;

    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }

    double denom = n * sumX2 - sumX * sumX;
    if (denom == 0)
        throw runtime_error("Cannot fit line: all x values are identical (zero variance)");

    double b = (n * sumXY - sumX * sumY) / denom;
    double a = (sumY - b * sumX) / n;
    return {a, b};
}

int main()
{
    vector<double> x = {1, 2, 3, 4};
    vector<double> y = {2, 4, 6, 8};

    auto [a, b] = linearRegression(x, y);
    cout << "Linear Regression: y = " << a << " + " << b << "x\n";

    return 0;
}
