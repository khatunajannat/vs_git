#include <windows.h>
#include <psapi.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

#pragma comment(lib, "Psapi.lib") // Needed for MSVC linking

// Replace with your CPU's approximate average power (Watts)
#define CPU_POWER_WATTS 65.0
// Bangladesh grid emission factor (kg CO2 / kWh)
#define BD_EMISSION_FACTOR 0.62

const int N = 45;
const int INF = INT_MAX / 4;

// i) Sparse Graph: 45 vertices, 150-200 randomly generated edges.
// ii) Dense Graph: 45 vertices, complete graph (990 edges).
vector<vector<int>> generateGraph(int n, bool dense)
{
    vector<vector<int>> W(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        W[i][i] = 0;

    if (dense)
    {
        // Complete graph: n*(n-1)/2 = 990 edges for n = 45
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int w = rand() % 100 + 1; // weight 1-100
                W[i][j] = w;
                W[j][i] = w;
            }
        }
    }
    else
    {
        // Sparse graph: 150-200 randomly generated edges
        int targetEdges = 150 + rand() % 51; // 150-200
        int edgesAdded = 0;

        while (edgesAdded < targetEdges)
        {
            int u = rand() % n;
            int v = rand() % n;
            if (u != v && W[u][v] == INF)
            {
                int w = rand() % 100 + 1; // weight 1-100
                W[u][v] = w;
                W[v][u] = w;
                edgesAdded++;
            }
        }
    }
    return W;
}

// FLOYD-WARSHALL(W)
vector<vector<int>> floydWarshall(vector<vector<int>> &W)
{
    int n = W.size();
    vector<vector<int>> D = W;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
    return D;
}

int main()
{
    srand((unsigned)time(0));
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    PROCESS_MEMORY_COUNTERS_EX pmc;

    // ================= Sparse Graph =================
    vector<vector<int>> W1 = generateGraph(N, false);

    QueryPerformanceCounter(&start);
    vector<vector<int>> D1 = floydWarshall(W1);
    QueryPerformanceCounter(&end);

    double elapsed1 = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy1 = CPU_POWER_WATTS * elapsed1;     // Joules
    double energy_kWh1 = energy1 / 3.6e6;            // kWh
    double co2_1 = energy_kWh1 * BD_EMISSION_FACTOR; // kg CO2

    printf("===== Sparse Graph (Vertices: %d) =====\n", N);
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc)))
    {
        SIZE_T peakMemUsed1 = pmc.PeakWorkingSetSize; // Peak RAM usage

        printf("Execution time: %.6f seconds\n", elapsed1);
        printf("Estimated energy consumption: %.2f Joules\n", energy1);
        printf("Peak Memory Usage: %zu KB\n", peakMemUsed1 / 1024);
        printf("Estimated CO2 emissions (Bangladesh): %.8f kg\n", co2_1);
    }
    else
    {
        printf("Failed to get memory info.\n");
    }
    printf("\n");

    // ================= Dense Graph =================
    vector<vector<int>> W2 = generateGraph(N, true);

    QueryPerformanceCounter(&start);
    vector<vector<int>> D2 = floydWarshall(W2);
    QueryPerformanceCounter(&end);

    double elapsed2 = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    double energy2 = CPU_POWER_WATTS * elapsed2;     // Joules
    double energy_kWh2 = energy2 / 3.6e6;            // kWh
    double co2_2 = energy_kWh2 * BD_EMISSION_FACTOR; // kg CO2

    printf("===== Dense Graph (Vertices: %d) =====\n", N);
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc)))
    {
        SIZE_T peakMemUsed2 = pmc.PeakWorkingSetSize; // Peak RAM usage

        printf("Execution time: %.6f seconds\n", elapsed2);
        printf("Estimated energy consumption: %.2f Joules\n", energy2);
        printf("Peak Memory Usage: %zu KB\n", peakMemUsed2 / 1024);
        printf("Estimated CO2 emissions (Bangladesh): %.8f kg\n", co2_2);
    }
    else
    {
        printf("Failed to get memory info.\n");
    }

    return 0;
}
