#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<long long>> d(n, vector<long long>(n));
    for (auto &row : d)
        for (auto &x : row)
            cin >> x;

    // dp[mask][i] = min cost to visit cities in mask, ending at i (start = 0)
    vector<vector<long long>> dp(1 << n, vector<long long>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++)
    {
        if (!(mask & 1))
            continue; // must include start city 0
        for (int i = 0; i < n; i++)
        {
            if (!(mask >> i & 1) || dp[mask][i] == INF)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (mask >> j & 1)
                    continue;
                int nm = mask | (1 << j);
                dp[nm][j] = min(dp[nm][j], dp[mask][i] + d[i][j]);
            }
        }
    }

    long long ans = INF;
    int full = (1 << n) - 1;
    for (int i = 1; i < n; i++)
        if (dp[full][i] < INF)
            ans = min(ans, dp[full][i] + d[i][0]);

    if (n == 1)
        ans = 0;
    cout << ans << "\n";
    return 0;
}