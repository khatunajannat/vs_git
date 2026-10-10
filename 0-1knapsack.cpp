#include <bits/stdc++.h>
using namespace std;

// ---------- 2D DP (also reconstructs chosen items) ----------
// Time: O(n * W), Space: O(n * W)
int knapsack2D(const vector<int> &wt, const vector<int> &val, int W,
               vector<int> &chosen)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            dp[i][w] = dp[i - 1][w]; // skip item i
            if (wt[i - 1] <= w)      // take item i
                dp[i][w] = max(dp[i][w],
                               val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    }

    // Backtrack to find which items were picked
    int w = W;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            chosen.push_back(i - 1);
            w -= wt[i - 1];
        }
    }
    reverse(chosen.begin(), chosen.end());
    return dp[n][W];
}

// ---------- 1D DP (space optimized) ----------
// Time: O(n * W), Space: O(W)
int knapsack1D(const vector<int> &wt, const vector<int> &val, int W)
{
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < (int)wt.size(); i++)
    {
        for (int w = W; w >= wt[i]; w--)
        { // iterate backwards!
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

int main()
{
    int n, W;
    cout << "Enter number of items and capacity: ";
    cin >> n >> W;

    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for (int &x : wt)
        cin >> x;
    cout << "Enter values: ";
    for (int &x : val)
        cin >> x;

    vector<int> chosen;
    int best = knapsack2D(wt, val, W, chosen);

    cout << "Max value (2D DP): " << best << "\n";
    cout << "Max value (1D DP): " << knapsack1D(wt, val, W) << "\n";
    cout << "Items chosen (0-indexed): ";
    for (int i : chosen)
        cout << i << " ";
    cout << "\n";
    return 0;
}