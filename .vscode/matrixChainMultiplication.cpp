#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void matrixChainOrder(vector<int> &p, vector<vector<int>> &m, vector<vector<int>> &s)
{
    int n = p.size() - 1; // number of matrices

    // m and s are (n+1) x (n+1), 1-indexed
    m.assign(n + 1, vector<int>(n + 1, 0));
    s.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int len = 2; len <= n; len++)
    { // chain length
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Print the optimal parenthesization, e.g. ((A1(A2A3))A4)
void printOptimalParens(vector<vector<int>> &s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    // Example: matrices A1(10x30), A2(30x5), A3(5x60)
    // p = {10, 30, 5, 60} means dimensions 10x30, 30x5, 5x60
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};

    vector<vector<int>> m, s;
    matrixChainOrder(p, m, s);

    int n = p.size() - 1;

    cout << "Minimum number of multiplications: " << m[1][n] << endl;
    cout << "Optimal parenthesization: ";
    printOptimalParens(s, 1, n);
    cout << endl;

    return 0;
}