#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> a;
vector<double> b;
vector<double> x;

int n;

void gaussSeidle()
{

    cout << fixed << setprecision(6);
    double sum;
    int iter = 1;

    while (iter < 15)
    {

        cout << "Iteration: " << iter;
        for (int i = 0; i < n; i++)
        {

            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += a[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / a[i][i];
            cout << "x[ " << i << "] = " << x[i] << "\t";
        }
        cout << endl;
        iter++;
    }
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

    cout << "Result: " << endl;
    gaussSeidle();
}

/*
3
5 2 1
1 4 2
1 2 5
 12 15 20




*/
