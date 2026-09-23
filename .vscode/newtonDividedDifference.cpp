#include <bits/stdc++.h>
using namespace std;

void divided_difference(vector<double> &Xarr, vector<double> &Yarr, int n, double x)
{
    vector<vector<double>> table(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        table[i][0] = Yarr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            table[j][i] = (table[j + 1][i - 1] - table[j][i - 1]) / (Xarr[j + i] - Xarr[j]);
        }
    }

    double result = table[0][0];
    double term = 1;

    for (int i = 1; i < n; i++)
    {
        term = term * (x - Xarr[i - 1]);
        result = result + term * table[0][i];
    }

    cout << result << endl;
}

int main()
{
    cout << fixed << setprecision(3);
    vector<double> Xarr = {5, 7, 11, 13, 21};
    vector<double> Yarr = {150, 392, 1452, 2366, 9702};
    int n = 5;
    double x = 6;

    divided_difference(Xarr, Yarr, n, x);
    return 0;
}
