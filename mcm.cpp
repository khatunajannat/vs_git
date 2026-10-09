#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// prints the optimal parenthesization
void printOrder(vector<vector<int>> &s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printOrder(s, i, s[i][j]);
    printOrder(s, s[i][j] + 1, j);
    cout << ")";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; // number of matrices
    cin >> n;
    vector<long long> p(n + 1); // matrix i has size p[i-1] x p[i]
    for (auto &x : p)
        cin >> x;

    // dp[i][j] = min scalar multiplications to compute A_i ... A_j
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                long long cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum multiplications: " << dp[1][n] << "\n";
    cout << "Order: ";
    printOrder(s, 1, n);
    cout << "\n";
    return 0;
}