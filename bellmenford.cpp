#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, m, src;
    cin >> n >> m >> src;

    vector<Edge> edges(m);
    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;

    vector<int> dist(n, INF);
    dist[src] = 0;

    // Relax all edges (n - 1) times
    for (int i = 1; i < n; i++)
    {
        for (auto &e : edges)
        {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }

    // One more pass: if anything still improves, there is a negative cycle
    for (auto &e : edges)
    {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
        {
            cout << "Negative cycle detected!\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Distance to " << i << " = ";
        if (dist[i] == INF)
            cout << "unreachable\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}