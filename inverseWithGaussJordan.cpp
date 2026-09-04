#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> a;

int n;

void printAugmented()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << a[i][j] << "  ";
            if (j == n - 1)
                cout << "  | ";
        }
        cout << endl;
    }
}

void printInverse()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

void augmentIdentity()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            if (j - n == i)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
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
    }
}

void GaussJordanInverse()
{
    for (int i = 0; i < n; i++)
    {
        partialPivot(i);

        if (a[i][i] == 0)
        {
            cout << "Mathematical Error!" << endl;
            return;
        }

        double normalize = a[i][i];
        for (int l = 0; l < 2 * n; l++)
        {
            a[i][l] = a[i][l] / normalize;
        }

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double pivot = a[j][i] / a[i][i];
                for (int k = 0; k < 2 * n; k++)
                {
                    a[j][k] = a[j][k] - pivot * a[i][k];
                }
            }
        }
    }
    printAugmented();
    printInverse();
}

int main()
{
    cin >> n;
    a = vector<vector<double>>(n, vector<double>(2 * n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    augmentIdentity();
    GaussJordanInverse();
}

/*
3
1 -3 1
2 -8 8 -6 3 -15
*/