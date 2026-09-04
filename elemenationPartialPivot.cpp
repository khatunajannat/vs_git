#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> a;
vector<double> b;
vector<double> x;

int n;

void printUpp_Tri()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << "  | " << b[i] << endl;
    }
}

void partialPivot(int i)
{
    int maxRow = i;
    double maxVal = fabs(a[i][i]);

    for (int k = i + 1; k < n; k++)
    {
        if (fabs(a[k][i]) > maxVal)
        {
            maxVal = fabs(a[k][i]);
            maxRow = k;
        }
    }

    if (maxRow != i)
    {
        swap(a[i], a[maxRow]);
        swap(b[i], b[maxRow]);
    }
}

void forwardElem()
{
    double pivot = 0;
    for (int i = 0; i < n; i++)
    {
        partialPivot(i);
        for (int j = i + 1; j < n; j++)
        {
            pivot = a[j][i] / a[i][i];
            for (int k = 0; k < n; k++)
            {
                a[j][k] = a[j][k] - pivot * a[i][k];
            }
            b[j] = b[j] - b[i] * pivot;
        }
    }
}

void backwardSubstitution()
{
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = n - 1; j > 0; j--)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }
}

void printSolution()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "  ";
    }
}

void gaussElem()
{

    forwardElem();
    printUpp_Tri();
    backwardSubstitution();
    printSolution();
}

int main()
{

    cin >> n;
    a = vector<vector<double>>(n, vector<double>(n, 0));
    b = vector<double>(n, 0);
    x = vector<double>(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    gaussElem();
}

/*
3
1 -3 1
2 -8 8 -6 3 -15
4 -2 9
*/