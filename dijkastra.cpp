// Dijkstra's shortest path algorithm (priority queue, O((V + E) log V))
// Works for graphs with non-negative edge weights.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 4;

struct Edge
{
    int to;
    ll w;
};

// Returns distances from src; fills parent[] for path reconstruction.
vector<ll> dijkstra(int src, const vector<vector<Edge>> &adj, vector<int> &parent)
{
    int n = adj.size();
    vector<ll> dist(n, INF);
    parent.assign(n, -1);

    // min-heap of (distance, node)
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue; // stale entry, skip

        for (const Edge &e : adj[u])
        {
            if (dist[u] + e.w < dist[e.to])
            {
                dist[e.to] = dist[u] + e.w;
                parent[e.to] = u;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

// Rebuild the path from src to target using the parent array.
vector<int> getPath(int target, const vector<int> &parent)
{
    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    //   n m            (nodes numbered 0..n-1, m edges)
    //   u v w          (m lines, undirected edge u--v with weight w)
    //   src            (source node)
    //
    // Example:
    //   5 6
    //   0 1 4
    //   0 2 1
    //   2 1 2
    //   1 3 1
    //   2 3 5
    //   3 4 3
    //   0
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line for a directed graph
    }

    int src;
    cin >> src;

    vector<int> parent;
    vector<ll> dist = dijkstra(src, adj, parent);

    for (int i = 0; i < n; i++)
    {
        cout << "Distance to " << i << ": ";
        if (dist[i] == INF)
        {
            cout << "unreachable\n";
            continue;
        }
        cout << dist[i] << "  | path: ";
        vector<int> path = getPath(i, parent);
        for (size_t j = 0; j < path.size(); j++)
        {
            cout << path[j] << (j + 1 < path.size() ? " -> " : "\n");
        }
    }
    return 0;
}