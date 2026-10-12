#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
vector<long long> w;
vector<int> x;

void sumOfSub(long long s, int k, long long r)
{
    x[k] = 1;
    if (s + w[k] == m)
    {
        for (int j = 1; j <= k; j++)
            cout << x[j] << " ";
        cout << "\n";
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        sumOfSub(s + w[k], k + 1, r - w[k]);
    }
    if (s + r - w[k] >= m && s + w[k + 1] <= m)
    {
        x[k] = 0;
        sumOfSub(s, k + 1, r - w[k]);
    }
}

int main()
{
    n = 6;
    m = 30;
    w = {0, 5, 10, 12, 13, 15, 18, (long long)4e18};
    x.assign(n + 2, 0);
    long long total = 0;
    for (int i = 1; i <= n; i++)
        total += w[i];
    sumOfSub(0, 1, total);
}