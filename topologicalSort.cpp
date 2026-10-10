#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    cout << "Enter edges (u v means u -> v):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    // Step 1: push all vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    // Step 2: remove a vertex, reduce indegree of its neighbours
    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // Step 3: if not all vertices are in the order, there is a cycle
    if ((int)order.size() != n)
    {
        cout << "Cycle detected! Topological sort not possible.\n";
        return 0;
    }

    cout << "Topological order: ";
    for (int x : order)
        cout << x << " ";
    cout << "\n";
    return 0;
}