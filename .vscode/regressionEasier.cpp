/*
 * ============================================================
 *  LINEAR REGRESSION - implemented directly from pseudocode
 * ============================================================
 *  1. Read Number of Data n
 *  2. Read xi and yi For i = 1 to n
 *  3. Initialize sumX, sumX2, sumY, sumXY = 0
 *  4. Calculate Required Sums (loop i = 1 to n)
 *  5. Calculate a and b
 *  6. Display Value of a and b
 *  7. Stop
 * ============================================================
 */

#include <iostream>
using namespace std;

int main()
{
    // ---------- Step 1: Read Number of Data n ----------
    //    int n;
    //    cout << "Enter number of data points (n): ";
    //    cin >> n;
    //
    //    // ---------- Step 2: Read xi and yi for i = 1 to n ----------
    //    double x[n], y[n];
    //    for (int i = 0; i < n; i++) {
    //        cout << "Enter x" << (i + 1) << " y" << (i + 1) << ": ";
    //        cin >> x[i] >> y[i];
    //    }
    int n = 5;
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {5, 4, 3, 2, 5};

    // ---------- Step 3: Initialize ----------
    double sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;

    // ---------- Step 4: Calculate Required Sums ----------
    for (int i = 0; i < n; i++)
    {
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i] * x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i] * y[i];
    }

    // ---------- Step 5: Calculate a and b ----------
    double denom = n * sumX2 - sumX * sumX;

    // Guard against division by zero (all x values identical)
    if (denom == 0)
    {
        cout << "Error: Cannot fit line, all x values are identical.\n";
        return 1;
    }

    double b = (n * sumXY - sumX * sumY) / denom;
    double a = (sumY - b * sumX) / n;

    // ---------- Step 6: Display Value of a and b ----------
    cout << "\na = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "Regression Line: y = " << a << " + " << b << "x\n";

    // ---------- Step 7: Stop ----------
    return 0;
}
