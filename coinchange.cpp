#include <bits/stdc++.h>
using namespace std;

// Greedy coin change: always take the largest coin that fits.
// Correct only for canonical coin systems (e.g., 1, 5, 10, 25, 50, 100).
vector<int> greedyCoinChange(vector<int> coins, int amount)
{
    sort(coins.begin(), coins.end(), greater<int>());
    vector<int> used;
    for (int c : coins)
    {
        while (amount >= c)
        {
            amount -= c;
            used.push_back(c);
        }
    }
    if (amount != 0)
        return {}; // exact change not possible
    return used;
}

// DP coin change: minimum coins for any coin system.
// Returns -1 if the amount cannot be formed.
int dpCoinChange(const vector<int> &coins, int amount)
{
    const int INF = INT_MAX / 2;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int a = 1; a <= amount; a++)
        for (int c : coins)
            if (a >= c)
                dp[a] = min(dp[a], dp[a - c] + 1);
    return dp[amount] >= INF ? -1 : dp[amount];
}

int main()
{
    // Greedy works here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int amount = 2093;

    vector<int> result = greedyCoinChange(coins, amount);
    if (result.empty() && amount != 0)
    {
        cout << "Cannot make " << amount << " with the given coins.\n";
    }
    else
    {
        cout << "Amount: " << amount << "\n";
        cout << "Greedy coins used (" << result.size() << "): ";
        for (int c : result)
            cout << c << " ";
        cout << "\n";
    }

    // Greedy fails here: for 6 with {1, 3, 4}, greedy gives 4+1+1 (3 coins),
    // but the best is 3+3 (2 coins).
    vector<int> tricky = {1, 3, 4};
    int target = 6;
    cout << "\nCoins {1,3,4}, amount 6\n";
    cout << "Greedy count: " << greedyCoinChange(tricky, target).size() << "\n";
    cout << "DP count (optimal): " << dpCoinChange(tricky, target) << "\n";

    return 0;
}