#include <bits/stdc++.h>
using namespace std;

string a, b;
int n, m;
int best = 0;
string bestStr;
long long nodesVisited = 0;
vector<array<int, 256>> sufA, sufB; // suffix character counts

int upperBound(int i, int j, int curLen)
{
    int bound = curLen;
    for (int c = 0; c < 256; c++)
        bound += min(sufA[i][c], sufB[j][c]);
    return bound;
}

void branchAndBound(int i, int j, string &cur)
{
    nodesVisited++;

    if ((int)cur.size() > best)
    {
        best = cur.size();
        bestStr = cur;
    }
    if (i == n || j == m)
        return;

    // Bound step: prune if this node cannot beat the best answer so far
    if (upperBound(i, j, cur.size()) <= best)
        return;

    if (a[i] == b[j])
    {
        cur.push_back(a[i]);
        branchAndBound(i + 1, j + 1, cur);
        cur.pop_back();
    }
    else
    {
        // Explore the more promising branch first (higher bound)
        int bi = upperBound(i + 1, j, cur.size());
        int bj = upperBound(i, j + 1, cur.size());
        if (bi >= bj)
        {
            if (bi > best)
                branchAndBound(i + 1, j, cur);
            if (bj > best)
                branchAndBound(i, j + 1, cur);
        }
        else
        {
            if (bj > best)
                branchAndBound(i, j + 1, cur);
            if (bi > best)
                branchAndBound(i + 1, j, cur);
        }
    }
}
//branch and bound function
string lcsBranchAndBound(const string &x, const string &y)
{
    a = x;
    b = y;
    n = a.size();
    m = b.size();
    best = 0;
    bestStr = "";
    nodesVisited = 0;

    sufA.assign(n + 1, array<int, 256>{});
    sufB.assign(m + 1, array<int, 256>{});
    for (int i = n - 1; i >= 0; i--)
    {
        sufA[i] = sufA[i + 1];
        sufA[i][(unsigned char)a[i]]++;
    }
    for (int j = m - 1; j >= 0; j--)
    {
        sufB[j] = sufB[j + 1];
        sufB[j][(unsigned char)b[j]]++;
    }

    string cur;
    branchAndBound(0, 0, cur);
    return bestStr;
}

// Standard DP, used only to verify the branch and bound answer.
int lcsDP(const string &x, const string &y)
{
    int p = x.size(), q = y.size();
    vector<vector<int>> dp(p + 1, vector<int>(q + 1, 0));
    for (int i = 1; i <= p; i++)
        for (int j = 1; j <= q; j++)
            dp[i][j] = (x[i - 1] == y[j - 1]) ? dp[i - 1][j - 1] + 1
                                              : max(dp[i - 1][j], dp[i][j - 1]);
    return dp[p][q];
}

int main()
{
    vector<pair<string, string>> tests = {
        {"AGGTAB", "GXTXAYB"},
        {"ABCBDAB", "BDCABA"},
        {"AAAA", "BBBB"},
        {"programming", "gaming"}};

    for (auto &t : tests)
    {
        string res = lcsBranchAndBound(t.first, t.second);
        int dpLen = lcsDP(t.first, t.second);
        cout << "A = " << t.first << ", B = " << t.second << "\n";
        cout << "  Branch & Bound LCS : " << res << " (length " << res.size() << ")\n";
        cout << "  DP length (check)  : " << dpLen
             << (dpLen == (int)res.size() ? "  [match]" : "  [MISMATCH]") << "\n";
        cout << "  Nodes visited      : " << nodesVisited << "\n\n";
    }
    return 0;
}