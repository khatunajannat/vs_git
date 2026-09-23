#include "bits/stdc++.h"
using namespace std;

vector<double> Gauss(vector<vector<double>> &A, vector<double> &B)
{
    int n = B.size();
    vector<double> X(n, 0);
    double pivot;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pivot = A[j][i] / A[i][i];
            for (int k = 0; k < n; k++)
            {
                A[j][k] -= pivot * A[i][k];
            }
            B[j] -= pivot * B[i];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = n - 1; j > i; j--)
        {
            sum += A[i][j] * X[j];
        }
        X[i] = (B[i] - sum) / A[i][i];
    }
    return X;
}

vector<double> polynomialRegression(vector<double> &x, vector<double> &y, double degree)
{
    int n = x.size();

    vector<vector<double>> A(degree + 1, vector<double>(degree + 2, 0));

    vector<double> B(degree + 1, 0);

    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= degree; j++)
        {
            for (int k = 0; k < n; k++)
            {
                A[i][j] += pow(x[k], i + j);
            }
        }
        for (int k = 0; k < n; k++)
        {
            B[i] += pow(x[k], i) * y[k];
        }
    }
    vector<double> coeff = Gauss(A, B);

    return coeff;
}

int main()
{
    vector<double> x = {1, 2, 3, 4};
    vector<double> y = {2, 4, 6, 8};

    vector<double> coeff = polynomialRegression(x, y, 2);

    double a1 = coeff[0];
    double a2 = coeff[1];
    double a3 = coeff[2];
    double a4 = coeff[3];
    double a5 = coeff[4];

    cout << a1 << " " << a2 << " " << a3 << endl;

    cout << "y= " << a1 << " + " << a2 << "*x + " << a3 << "*x^2" << endl;

    // cout<<"y= "<<a1<<" + "<<a2<<"*x + "<<a3<<"*x^2 + "<<a4<<"*x^3 + "<<a5<<"*x4"<<endl;
}
