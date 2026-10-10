#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start, finish, id;
};

// Sort by finish time (earliest finish first)
bool cmp(Activity a, Activity b)
{
    return a.finish < b.finish;
}

int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> act(n);
    cout << "Enter start and finish time of each activity:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> act[i].start >> act[i].finish;
        act[i].id = i + 1;
    }

    // Step 1: sort by finish time
    sort(act.begin(), act.end(), cmp);

    // Step 2: pick the first activity
    vector<int> selected;
    selected.push_back(act[0].id);
    int lastFinish = act[0].finish;

    // Step 3: pick next activity if it starts after the last one finishes
    for (int i = 1; i < n; i++)
    {
        if (act[i].start >= lastFinish)
        {
            selected.push_back(act[i].id);
            lastFinish = act[i].finish;
        }
    }

    cout << "\nMaximum activities: " << selected.size() << "\n";
    cout << "Selected activities: ";
    for (int id : selected)
        cout << id << " ";
    cout << "\n";
    return 0;
}