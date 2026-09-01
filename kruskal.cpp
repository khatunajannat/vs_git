
#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <vector>

#pragma comment(lib, "Psapi.lib")

#define CPU_POWER_WATTS 65.0

#define BD_EMISSION_FACTOR 0.62

using namespace std;

struct Edge
{
    int u, v, w;
};

int findSet(vector<int> &parent, int x)
{
    while (parent[x] != x)
    {
        x = parent[x];
    }
    return x;
}

void unionSets(vector<int> &parent, int a, int b)
{
    int rootA = findSet(parent, a);
    int rootB = findSet(parent, b);
    if (rootA != rootB)
    {
        parent[rootB] = rootA;
    }
}

void sortEdgesByWeight(vector<Edge> &edges)
{
    int count = edges.size();
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

bool edgeExists(vector<Edge> &edges, int u, int v)
{
    for (int i = 0; i < (int)edges.size(); i++)
    {
        if ((edges[i].u == u && edges[i].v == v) ||
            (edges[i].u == v && edges[i].v == u))
        {
            return true;
        }
    }
    return false;
}

vector<Edge> generateSparseGraph(int V, int targetEdges)
{
    vector<Edge> edges;

    for (int i = 1; i < V; i++)
    {
        int j = rand() % i;
        int w = rand() % 100 + 1;
        edges.push_back({i, j, w});
    }

    while ((int)edges.size() < targetEdges)
    {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v)
            continue;
        if (edgeExists(edges, u, v))
            continue;

        int w = rand() % 100 + 1;
        edges.push_back({u, v, w});
    }

    return edges;
}

vector<Edge> generateDenseGraph(int V)
{
    vector<Edge> edges;

    for (int u = 0; u < V; u++)
    {
        for (int v = u + 1; v < V; v++)
        {
            int w = rand() % 100 + 1;
            edges.push_back({u, v, w});
        }
    }

    return edges;
}

int Kruskal(int V, vector<Edge> edges, int &mstEdgeCount)
{
    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    sortEdgesByWeight(edges);

    int totalWeight = 0;
    mstEdgeCount = 0;

    for (int i = 0; i < (int)edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (findSet(parent, u) != findSet(parent, v))
        {
            unionSets(parent, u, v);
            totalWeight += edges[i].w;
            mstEdgeCount++;
        }
    }

    return totalWeight;
}

void runAndMeasure(const char *label, int V, vector<Edge> &edges)
{
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    int mstEdgeCount = 0;
    int totalWeight = Kruskal(V, edges, mstEdgeCount);

    QueryPerformanceCounter(&end);

    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy = CPU_POWER_WATTS * elapsed;
    double energy_kWh = energy / 3.6e6;
    double co2 = energy_kWh * BD_EMISSION_FACTOR;

    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc)))
    {
        SIZE_T peakMemUsed = pmc.PeakWorkingSetSize;

        printf("===== Kruskal's Algorithm - %s =====\n", label);
        printf("Vertices: %d, Edges: %zu, MST edges found: %d\n", V, edges.size(), mstEdgeCount);
        printf("MST total weight: %d\n", totalWeight);
        printf("Execution time: %.6f seconds\n", elapsed);
        printf("Estimated energy consumption: %.6f Joules\n", energy);
        printf("Peak Memory Usage: %zu KB\n", peakMemUsed / 1024);
        printf("Estimated CO2 emissions (Bangladesh): %.9f kg\n\n", co2);
    }
    else
    {
        printf("Failed to get memory info.\n");
    }
}

int main()
{
    srand((unsigned)time(nullptr));

    int V = 45;

    vector<Edge> sparse = generateSparseGraph(V, 175);
    runAndMeasure("Sparse Graph (175 edges)", V, sparse);

    vector<Edge> dense = generateDenseGraph(V);
    runAndMeasure("Dense Graph (990 edges, complete)", V, dense);

    return 0;
}
