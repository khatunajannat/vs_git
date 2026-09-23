#include <bits/stdc++.h>
using namespace std;

void lagrange(vector<double> &Xarr, vector<double> &Yarr, int n, double x)
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        double y = Yarr[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                y = y * ((x - Xarr[j]) / (Xarr[i] - Xarr[j]));
            }
        }
        result = result + y;
    }

    cout << result << endl;
}

int main()
{
    cout << fixed << setprecision(3);
    vector<double> Xarr = {5, 6, 9, 11};
    vector<double> Yarr = {12, 13, 14, 16};
    int n = 4;
    double x = 10;

    lagrange(Xarr, Yarr, n, x);
    return 0;
}
