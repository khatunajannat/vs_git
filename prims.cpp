#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <vector>
#pragma comment(lib, "Psapi.lib")
#define CPU_POWER_WATTS 65.0
#define BD_EMISSION_FACTOR 0.62
using namespace std;

vector<vector<int>> generateSparseGraph(int V, int targetEdges)
{
    vector<vector<int>> graph(V, vector<int>(V, 0));
    int edgeCount = 0;
    for (int i = 1; i < V; i++)
    {
        int j = rand() % i;
        int w = rand() % 100 + 1;
        graph[i][j] = w;
        graph[j][i] = w;
        edgeCount++;
    }
    while (edgeCount < targetEdges)
    {
        int u = rand() % V;
        int v = rand() % V;
        if (u == v)
            continue;
        if (graph[u][v] != 0)
            continue;
        int w = rand() % 100 + 1;
        graph[u][v] = w;
        graph[v][u] = w;
        edgeCount++;
    }
    return graph;
}

vector<vector<int>> generateDenseGraph(int V)
{
    vector<vector<int>> graph(V, vector<int>(V, 0));
    for (int u = 0; u < V; u++)
    {
        for (int v = u + 1; v < V; v++)
        {
            int w = rand() % 100 + 1;
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }
    return graph;
}

int Prim(int V, vector<vector<int>> &graph, int root = 0)
{
    vector<int> weight(V, INT_MAX);
    vector<bool> inMST(V, false);
    weight[root] = 0;
    int mstWeight = 0;
    for (int count = 0; count < V; count++)
    {
        int u = -1;
        int best = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (!inMST[i] && weight[i] < best)
            {
                best = weight[i];
                u = i;
            }
        }
        if (u == -1)
            break;
        inMST[u] = true;
        mstWeight += weight[u];
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < weight[v])
            {
                weight[v] = graph[u][v];
            }
        }
    }
    return mstWeight;
}

void runAndMeasure(const char *label, int V, vector<vector<int>> &graph, size_t edgeCount)
{
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    int mstWeight = Prim(V, graph, 0);
    QueryPerformanceCounter(&end);
    double elapsed = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy = CPU_POWER_WATTS * elapsed;
    double energy_kWh = energy / 3.6e6;
    double co2 = energy_kWh * BD_EMISSION_FACTOR;
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc)))
    {
        SIZE_T peakMemUsed = pmc.PeakWorkingSetSize;
        printf("===== Prim's Algorithm - %s =====\n", label);
        printf("Vertices: %d, Edges: %zu\n", V, edgeCount);
        printf("MST total weight: %d\n", mstWeight);
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

    vector<vector<int>> sparse = generateSparseGraph(V, 175);
    runAndMeasure("Sparse Graph (175 edges)", V, sparse, 175);

    vector<vector<int>> dense = generateDenseGraph(V);
    runAndMeasure("Dense Graph (990 edges, complete)", V, dense, 990);

    return 0;
}
