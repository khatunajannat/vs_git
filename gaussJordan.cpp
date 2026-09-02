#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> a;
vector<double> b;

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

void printSolution()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << "  ";
    }
}

void printDiagonal()
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

void gaussJordan()
{

    double pivot = 0;
    for (int i = 0; i < n; i++)
    {
        double normalize = a[i][i];

        for (int l = 0; l < n; l++)
        {

            a[i][l] = a[i][l] / normalize;
        }
        b[i] = b[i] / normalize;

        for (int j = 0; j < n; j++)
        {
            if (i != j)
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
    printDiagonal();
    printSolution();
}

int main()
{

    cin >> n;
    a = vector<vector<double>>(n, vector<double>(n, 0));
    b = vector<double>(n, 0);

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

    gaussJordan();
}

/*
3
1 -3 1
2 -8 8
-6 3 -15
4 -2 9
*/
