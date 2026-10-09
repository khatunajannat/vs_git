#include <bits/stdc++.h>
using namespace std;

int p[100005];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<tuple<long long, int, int>> e(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        scanf("%d %d %lld", &u, &v, &w);
        e[i] = make_tuple(w, u, v);
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++)
        p[i] = i;

    long long cost = 0;
    int used = 0;
    for (auto &x : e)
    {
        int u = find(get<1>(x)), v = find(get<2>(x));
        if (u != v)
        {
            p[u] = v;
            cost += get<0>(x);
            used++;
        }
    }
    if (used == n - 1)
        printf("%lld\n", cost);
    else
        puts("IMPOSSIBLE");
}