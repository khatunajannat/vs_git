#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{

  return a[1] < b[1];
}

int activitySelection(vector<int> &start, vector<int> &finish)
{

  vector<vector<int>> arr;
  for (int i = 0; i < start.size(); i++)
  {

    arr.push_back({start[i], finish[i]});
  }

  sort(arr.begin(), arr.end(), compare);
  int cnt = 0;
  int j = 0;

  for (int i = 1; i < arr.size(); i++)
  {

    if (arr[i][0] > arr[j][1])
    {

      cnt++;
      j = i;
    }
  }

  return cnt;
}

int main()
{

  vector<int> start = {1, 3, 0, 4, 7};
  vector<int> finish = {2, 4, 6, 8, 8};

  cout << activitySelection(start, finish) << endl;
  return 0;
}
