#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];

    return a1 > b1;
}

double knapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();

    vector<vector<int>> item(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {

        item[i][0] = val[i];
        item[i][1] = wt[i];
    }

    sort(item.begin(), item.end(), compare);

    double result = 0;
    int currCapacity = capacity;
    for (int i = 0; i < n; i++)
    {

        if (item[i][1] <= currCapacity)
        {
            result += item[i][0];
            currCapacity -= item[i][1];
        }
        else
        {

            result += (1.0 * item[i][0] / item[i][1]) * currCapacity;
            break;
        }
    }

    return result;
}

int main()
{
    vector<int> val = {600, 100, 500};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    cout << knapsack(val, wt, capacity) << endl;
}
