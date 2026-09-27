
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 6;
    double x[] = {2, 3, 5, 4, 6, 8};
    double y[] = {45, 50, 58, 54, 65, 72};

    double sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;

    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    cout << "Sum(X)  = " << sumX << endl;
    cout << "Sum(Y)  = " << sumY << endl;
    cout << "Sum(XY) = " << sumXY << endl;
    cout << "Sum(X^2)= " << sumX2 << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Linear Regression Equation: Exam Score = " << b << " * StudyTime + " << a << endl;

    double predictX = 7;
    double predictY = a + b * predictX;
    cout << "Predicted score for study time " << predictX << " hours: " << predictY << " marks" << endl;

    // MSE = (1/n) * sum of (yi - yi_hat)^2
    double mse = 0;
    for (int i = 0; i < n; i++)
    {
        double yHat = a + b * x[i];
        mse += (y[i] - yHat) * (y[i] - yHat);
    }
    mse = mse / n;
    cout << "Mean Squared Error (MSE): " << mse << endl;

    return 0;
}
